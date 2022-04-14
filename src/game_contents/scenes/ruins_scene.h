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

#include "../resources.h"
#include "../tilesets.h"
#include "../player.h"
#include "../servant.h"

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



// InteractPoint point_servant;
// const char* point_servant_label = "Talk";
// void point_servant_interact(InteractPoint* self){
//     GameServer_set_dialog(game_server, &dialog_servant);
// }



void scene_ruins_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 1, 7);

    // setup interact points
    // game_server->interact_points[0] = &point_servant;
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
    // point_servant.action_name_str = point_servant_label;
    // point_servant.interact = point_servant_interact;
    // point_servant.x = 6;
    // point_servant.y = 7;

    // point_bulleitin_board.action_name_str = point_bulleitin_board_label;
    // point_bulleitin_board.interact = point_bulleitin_board_interact;
    // point_bulleitin_board.x = 13;
    // point_bulleitin_board.y = 9;

    // dialog
    // Dialog_new(&dialog_servant);
    // dialog_servant.text = dialog_servant_text;
    // dialog_servant.choice1 = dialog_servant_choice1;
    // dialog_servant.choice2 = dialog_servant_choice2;
    // dialog_servant.next1 = &dialog_servant_1;
    // Dialog_new(&dialog_servant_1);
    // dialog_servant_1.text = dialog_servant_1_text;
    // dialog_servant_1.choice1 = dialog_servant_1_choice1;
    // dialog_servant_1.next1 = &dialog_servant_2;
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
