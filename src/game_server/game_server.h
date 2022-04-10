#if !defined(GAME_SERVER_H)
#define GAME_SERVER_H

#include <stdlib.h>

// #include "../globals.h"

#include "../const.h"
#include "../screen_server/screen_server.h"
#include "../input_server/input_server.h"
#include "../text/textbox.h"
#include "dialog.h"
#include "scene.h"
#include "actor.h"
#include "interact_point.h"

// define input server
extern InputServer *input_server;
extern ScreenServer *screen_server;

#define MAX_ACTOR_NUM 32
#define MAX_LABEL_NUM 32
#define MAX_INTERACT_NUM 32

typedef struct
{
    Scene *scene;
    Actor *actor_list[MAX_ACTOR_NUM]; // player & npcs, only for display
    Actor *player;

    InteractPoint *interact_points[MAX_INTERACT_NUM]; // for conversations or machines
    bool interact_point_show[MAX_INTERACT_NUM];

    Dialog *dialog;
} GameServer;

void GameServer_render(GameServer *self, ScreenServer *server)
{
    Scene_draw_map(self->scene, server, 0, 0);
    // clear invalid region
    ScreenServer_dirty_clear(server);

    // render actor
    int i;
    Rect2D actor_rect;
    for (i = 0; i < MAX_ACTOR_NUM; i++)
    {
        // draw npc
        Actor *actor = self->actor_list[i];
        if (actor == NULL)
            break;

        int x = actor->display_x * 16;
        int y = actor->display_y * 16;
        draw_img_slice_color(server, x, y, actor->image, actor->color);
        // mark screen dirty
        actor_rect.x = x - actor->image.origin_x;
        actor_rect.y = y - actor->image.origin_y;
        actor_rect.w = actor->image.w;
        actor_rect.h = actor->image.h;
        ScreenServer_dirty_region(server, actor_rect);

        // custom draw function if provided
        if (actor->custom_draw != NULL)
            actor->custom_draw(actor);
    }
    // draw text buttons
    Rect2D text_rect;
    for (i = 0; i < MAX_INTERACT_NUM; i++)
    {
        InteractPoint *interact_point = self->interact_points[i];
        if (interact_point == NULL)
            break;
        if (self->interact_point_show[i])
        {
            char *text = self->interact_points[i]->action_name_str;
            int player_x = self->player->display_x * 16;
            int player_y = self->player->display_y * 16;

            int txt_w, txt_h;
            estimate_textbox_size(text, &txt_w, &txt_h);

            int screen_y = player_y + 16;                 // below player
            int screen_x = player_x + 16 / 2 - txt_w / 2; // center
            // clip to screen boundary
            screen_x = max(0, min(screen_x, RESOLUTION_X - txt_w));
            screen_y = max(0, min(screen_y, RESOLUTION_Y - txt_h));
            draw_textbox(server, text, screen_x, screen_y, WHITE, true, 0, false, 0);
            // mark dirty
            text_rect.x = screen_x;
            text_rect.y = screen_y;
            text_rect.w = txt_w;
            text_rect.h = txt_h;
            ScreenServer_dirty_region(server, text_rect);
        }
    }
}

void GameServer_init(GameServer *self)
{
    // remove all actors
    int i;
    for (i = 0; i < MAX_ACTOR_NUM; i++)
    {
        self->actor_list[i] = NULL;
    }
    self->player = NULL;
    // clear arrays
    for (i = 0; i < MAX_INTERACT_NUM; i++)
    {
        self->interact_points[i] = NULL;
        self->interact_point_show[i] = false;
    }
    self->dialog = NULL;

    // invalidate all screen
    ScreenServer_dirty_all(screen_server);
}

void GameServer_load_scene(GameServer *self, Scene *scene)
{
    // clear current scene
    GameServer_init(self);

    self->scene = scene;
    scene->setup(scene);

    // process actor start functions
    int i;
    for (i = 0; i < MAX_ACTOR_NUM; i++)
    {
        if (self->actor_list[i] == NULL)
            break;
        if (self->actor_list[i]->start != NULL)
            self->actor_list[i]->start(self->actor_list[i]);
    }

    // screen switch effect
    // This delay can prevent player from switching back to previous
    // scene immediately, if spawned on an interact point
    int w;
    const int inc_per_frame = 2;
    for (w = 0; w < RESOLUTION_X / 2; w += inc_per_frame)
    {
        draw_rect(screen_server, w, 0, inc_per_frame * 2, RESOLUTION_Y, 0);                // left rect
        draw_rect(screen_server, RESOLUTION_X - w, 0, inc_per_frame * 2, RESOLUTION_Y, 0); // right rect
        screen_server->flip(screen_server);
    }
    Rect2D dirty_region;
    for (w = 0; w < RESOLUTION_X / 2; w += inc_per_frame)
    {
        // left dirty
        dirty_region.h = RESOLUTION_Y;
        dirty_region.w = 16-1;
        dirty_region.x = RESOLUTION_X / 2 - w;
        dirty_region.y = 0;
        screen_server->dirty_region = dirty_region;
        Scene_draw_map(self->scene, screen_server, 0, 0);
        // right dirty
        dirty_region.h = RESOLUTION_Y;
        dirty_region.w = 16-1;
        dirty_region.x = RESOLUTION_X / 2 + w - 16;
        dirty_region.y = 0;
        screen_server->dirty_region = dirty_region;
        Scene_draw_map(self->scene, screen_server, 0, 0);
        // draw black box
        draw_rect(screen_server, RESOLUTION_X / 2 - w - 32, 0, 32, RESOLUTION_Y, 0); // left rect
        draw_rect(screen_server, RESOLUTION_X / 2 + w, 0, 32, RESOLUTION_Y, 0);      // right rect
        screen_server->flip(screen_server);
    }
    ScreenServer_dirty_all(screen_server);
}

void GameServer_move_player(GameServer *self, int x, int y)
{
    if (self->player == NULL)
    {
        return;
    }
    self->player->set_position(self->player, x, y);
}

void GameServer_process(GameServer *self)
{
    // check dialog ui first, skip everything else if ui is on
    if (self->dialog != NULL)
    {
        // do dialog animation
        {
            const int bg_lines = 5;
            // refresh the screen first
            ScreenServer_dirty_all(screen_server);
            GameServer_render(self, screen_server);
            draw_rect(screen_server, 3, 3, RESOLUTION_X - 6, (FONT_H + 1) * bg_lines, 0); // draw black box in front buffer
            screen_server->flip(screen_server);
            GameServer_render(self, screen_server);
            draw_rect(screen_server, 3, 3, RESOLUTION_X - 6, (FONT_H + 1) * bg_lines, 0); // draw black box in back buffer

            // render the animation
            int i = 0;
            int cursor_x = 5; // start with some padding
            int cursor_y = 5;
            while (true)
            {
                char c = self->dialog->text[i];
                if (c == '\0')
                    break;          // end of string
                else if (c == '\n') // new line
                {
                    cursor_y += FONT_H + 1;
                    cursor_x = 5;
                }
                else
                {
                    // normal text
                    draw_char(screen_server, cursor_x, cursor_y, c, WHITE);
                    cursor_x += FONT_W + 1;
                    // auto line warp
                    if (cursor_x > RESOLUTION_X - 6)
                    {
                        cursor_x = 5;
                        cursor_y += FONT_H + 1;
                    }
                }
                i += 1;
                // draw one more char
                char next = self->dialog->text[i];
                if(next != '\0' && next != '\n')
                    draw_char(screen_server, cursor_x, cursor_y, next, WHITE);
                
                screen_server->flip(screen_server);

                // special case for the first char
                if(i == 1){
                    draw_char(screen_server, 5, 5, self->dialog->text[0], WHITE);
                }
            }

            // show text options
            ScreenServer_dirty_clear(screen_server);
            
        }
        // do input check loop
        {
            // check key press and update
            while (true)
            {
                input_server->update(input_server);
                if (input_server->key_is_pressed(input_server, K_SCANCODE_F))
                {
                    ScreenServer_dirty_all(screen_server);
                    self->dialog = NULL;
                    break;
                }
            }
        }
    }

    // do actor process
    int i;
    for (i = 0; i < MAX_ACTOR_NUM; i++)
    {
        if (self->actor_list[i] == NULL)
            break;
        if (self->actor_list[i]->process != NULL)
            self->actor_list[i]->process(self->actor_list[i]);
    }

    // update text button for interact points
    for (i = 0; i < MAX_INTERACT_NUM; i++)
    {
        InteractPoint *interact_point = self->interact_points[i];
        if (interact_point == NULL)
            break;
        // check player position
        if (self->player->block_x == interact_point->x &&
            self->player->block_y == interact_point->y)
        {
            self->interact_point_show[i] = true;
        }
        else
        {
            self->interact_point_show[i] = false;
        }
    }
    // check text button press
    int active_button_index = -1;
    for (i = 0; i < MAX_INTERACT_NUM; i++)
    {
        InteractPoint *interact_point = self->interact_points[i];
        if (interact_point == NULL)
            break;
        if (self->interact_point_show[i] == true)
        {
            active_button_index = i;
            break;
        }
    }
    if (active_button_index >= 0 && input_server->key_is_pressed(input_server, K_SCANCODE_F))
    {
        self->interact_points[active_button_index]->interact(self->interact_points[active_button_index]);
    }
}

void GameServer_set_dialog(GameServer *self, Dialog *dialog)
{
    self->dialog = dialog;
}

GameServer *GameServer_new(GameServer *self)
{
    GameServer *server = self;
    if (server == NULL)
    {
        server = (GameServer *)calloc(1, sizeof(GameServer));
    }
    GameServer_init(server);
    return server;
}

#endif // GAME_SERVER_H
