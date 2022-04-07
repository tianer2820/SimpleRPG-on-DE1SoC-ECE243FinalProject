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
extern InputServer* input_server;

#define MAX_ACTOR_NUM 32
#define MAX_LABEL_NUM 32
#define MAX_INTERACT_NUM 32
#define MAX_DIALOG_QUEUE_NUM 32

typedef struct
{
    Scene *scene;
    Actor *actor_list[MAX_ACTOR_NUM]; // player & npcs, only for display
    Actor *player;

    InteractPoint *interact_points[MAX_INTERACT_NUM]; // for conversations or machines
    bool interact_point_show[MAX_INTERACT_NUM];

    Dialog* dialog_queue[MAX_DIALOG_QUEUE_NUM];
} GameServer;

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
    for (i = 0; i < MAX_DIALOG_QUEUE_NUM; i++)
    {
        self->dialog_queue[i] = NULL;
    }
    
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
}

void GameServer_process(GameServer *self)
{
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
        if (self->interact_point_show[i] == true){
            active_button_index = i;
            break;
        }
    }
    if(active_button_index >= 0 && input_server->key_is_pressed(input_server, K_SCANCODE_F)){
        self->interact_points[active_button_index]->interact(self->interact_points[active_button_index]);
    }
}

void GameServer_render(GameServer *self, ScreenServer *server)
{
    Scene_draw_map(self->scene, server, 0, 0);

    // render actor
    int i;
    for (i = 0; i < MAX_ACTOR_NUM; i++)
    {
        // draw npc
        Actor *actor = self->actor_list[i];
        if (actor == NULL)
            break;

        int x = actor->display_x * 16;
        int y = actor->display_y * 16;
        draw_img_slice_color(server, x, y, actor->image, actor->color);

        // custom draw function if provided
        if (actor->custom_draw != NULL)
            actor->custom_draw(actor);

        // draw text buttons
        for (i = 0; i < MAX_INTERACT_NUM; i++)
        {
            InteractPoint *interact_point = self->interact_points[i];
            if (interact_point == NULL)
                break;
            if (self->interact_point_show[i]){
                char* text = self->interact_points[i]->action_name_str;
                int player_x = self->player->display_x * 16;
                int player_y = self->player->display_y * 16;

                int txt_w, txt_h;
                estimate_textbox_size(text, &txt_w, &txt_h);

                int screen_y = player_y + 16; // below player
                int screen_x = player_x + 16/2 - txt_w / 2; // center
                 // clip to screen boundary
                screen_x = max(0, min(screen_x, RESOLUTION_X - txt_w));
                screen_y = max(0, min(screen_y, RESOLUTION_Y - txt_h));
                draw_textbox(server, text, screen_x, screen_y, WHITE, true, 0, false, 0);
            }
        }
    }
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
