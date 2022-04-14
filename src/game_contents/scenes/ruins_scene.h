#if !defined(RUINS_SCENE_H)
#define RUINS_SCENE_H

#include <stdlib.h>
#include "../../globals.h"
#include "scenes_globals.h"

#include "../../images/short_image.h"
#include "../../tilemap/tilemap.h"
#include "../../tilemap/tileset.h"
#include "../../game_server/scene.h"
#include "../../game_server/interact_point.h"

#include "../../paint_functions.h"

#include "../resources.h"
#include "../tilesets.h"
#include "../player.h"
#include "../monster.h"

const int mapdata_ruins_layer1[] = {
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
};
const int mapdata_ruins_layer2[] = {
-1,-1,-1,-1,-1,-1,-1,46,47,-1,-1,-1,14,15,-1,-1,-1,-1,-1,-1,
-1,-1,14,15,-1,-1,-1,-1,-1,-1,-1,-1,22,23,-1,-1,-1,-1,-1,-1,
906,-1,22,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,46,47,14,15,-1,
914,-1,-1,-1,-1,14,15,-1,-1,-1,14,15,-1,-1,-1,-1,-1,22,23,-1,
922,-1,43,908,-1,22,23,-1,906,-1,22,23,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,916,-1,-1,-1,-1,914,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,52,-1,-1,-1,-1,922,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
148,148,148,148,148,148,335,234,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,906,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,914,-1,43,-1,-1,-1,-1,14,15,-1,-1,-1,-1,-1,14,15,-1,-1,-1,
-1,922,-1,-1,14,15,-1,-1,22,23,906,-1,-1,-1,-1,22,23,-1,-1,-1,
-1,14,15,-1,22,23,14,15,-1,-1,914,-1,-1,45,-1,-1,-1,14,15,-1,
-1,22,23,-1,-1,-1,22,23,-1,-1,922,-1,14,15,-1,-1,-1,22,23,-1,
-1,46,47,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,23,-1,-1,-1,-1,-1,-1,
};


Tilemap tilemap_ruins_layer1;
Tilemap tilemap_ruins_layer2;



InteractPoint point_to_basement;
const char* point_to_basement_label = "Enter";
void point_to_basement_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_basement);
}


Dialog dialog_monster;
char *dialog_monster_text = "\
Monster: *roar*";
char *dialog_monster_choice1 = "F: Use weapon";

Dialog dialog_monster2;
char *dialog_monster2_text = "\
You used the weapon";
char *dialog_monster2_choice1 = "F: ...";


Dialog dialog_end;
char *dialog_end_text = "\
Achievement: Hero of the village";
char *dialog_end_choice1 = "F: ...";

Dialog dialog_end1;
char *dialog_end1_text = "\
Thanks for playing. Pixel arts from:\n\
pipoya.itch.io/pipoya-rpg-tileset-32x32\n\
superdark.itch.io/16x16-free-npc-pack\n\
snoopethduckduck.itch.io/guns\n\
penusbmic.itch.io/monster-pack-i\n\
";
char *dialog_end1_choice1 = "";

void weapon_animation(Dialog* self){
    ScreenServer_dirty_all(screen_server);
    GameServer_render(game_server, screen_server);
    screen_server->flip(screen_server);
    GameServer_render(game_server, screen_server);

    int i;
    short color_list[] = {RED, BLUE, YELLOW, GREEN, WHITE, 0, PINK};
    for (i = 0; i < 20; i++)
    {
        draw_line(screen_server,
                actor_player.base.display_x * 16,
                actor_player.base.display_y * 16,
                actor_monster.display_x * 16,
                actor_monster.display_y * 16, color_list[i % 7]);
        int j;
        for (j = 0; j < 4; j++)
        {
            screen_server->flip(screen_server);
        }
    }
    ImageSlice_new(&(actor_monster.image));
    ScreenServer_dirty_all(screen_server);
    GameServer_render(game_server, screen_server);
    screen_server->flip(screen_server);
    // GameServer_set_dialog(game_server, &dialog_end);
}


void scene_ruins_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 1, 7);

    // monster & soldiers if weapon picked up
    if(weapon_pickedup){
        game_server->actor_list[1] = (Actor*)&actor_monster;
        actor_monster.block_x = 12;
        actor_monster.block_y = 7;
        actor_monster.display_x = 12;
        actor_monster.display_y = 7;
        // add dialog
        actor_player.flip_x = false;
        GameServer_set_dialog(game_server, &dialog_monster);
    }

    // setup interact points
    game_server->interact_points[0] = &point_to_basement;
    // game_server->interact_points[1] = &point_bulleitin_board;
}


void init_scene_ruins()
{
    // tilemap layers
    tilemap_ruins_layer1.tileset = &simple_set;
    tilemap_ruins_layer1.map_data = mapdata_ruins_layer1;
    tilemap_ruins_layer1.w = 20;
    tilemap_ruins_layer1.h = 14;

    tilemap_ruins_layer2.tileset = &simple_set;
    tilemap_ruins_layer2.map_data = mapdata_ruins_layer2;
    tilemap_ruins_layer2.w = 20;
    tilemap_ruins_layer2.h = 14;

    // scene
    Scene_new(&scene_ruins); // clear init memory
    scene_ruins.map_layers[0] = &tilemap_ruins_layer1;
    scene_ruins.map_layers[1] = &tilemap_ruins_layer2;
    scene_ruins.ambient_color = WHITE;
    scene_ruins.setup = scene_ruins_setup;

    // interact points
    point_to_basement.action_name_str = point_to_basement_label;
    point_to_basement.interact = point_to_basement_interact;
    point_to_basement.x = 6;
    point_to_basement.y = 7;

    // point_bulleitin_board.action_name_str = point_bulleitin_board_label;
    // point_bulleitin_board.interact = point_bulleitin_board_interact;
    // point_bulleitin_board.x = 13;
    // point_bulleitin_board.y = 9;

    // dialog
    Dialog_new(&dialog_monster);
    dialog_monster.text = dialog_monster_text;
    dialog_monster.choice1 = dialog_monster_choice1;
    dialog_monster.next1 = &dialog_monster2;
    Dialog_new(&dialog_monster2);
    dialog_monster2.text = dialog_monster2_text;
    dialog_monster2.choice1 = dialog_monster2_choice1;
    dialog_monster2.effect = &weapon_animation;
    dialog_monster2.next1 = &dialog_end;


    Dialog_new(&dialog_end);
    dialog_end.text = dialog_end_text;
    dialog_end.choice1 = dialog_end1_choice1;
    dialog_end.next1 = &dialog_end1;
    Dialog_new(&dialog_end1);
    dialog_end1.text = dialog_end1_text;
    dialog_end1.choice1 = dialog_end1_choice1;
    // Dialog_new(&dialog_servant_2);
    // dialog_servant_2.text = dialog_servant_2_text;
    // dialog_servant_2.choice1 = dialog_servant_2_choice1;
    // dialog_servant_2.next1 = &dialog_servant_3;
    // Dialog_new(&dialog_servant_3);
    // dialog_servant_3.text = dialog_servant_3_text;
    // dialog_servant_3.choice1 = dialog_servant_3_choice1;

    // Dialog_new(&dialog_bulletin_board);
    // dialog_bulletin_board.text = dialog_bulletin_board_text;
    // dialog_bulletin_board.choice1 = dialog_bulletin_board_choice1;
}

#endif // RUINS_SCENE_H
