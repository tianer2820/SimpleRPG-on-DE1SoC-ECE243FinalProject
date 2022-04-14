#if !defined(BASEMENT_SCENE_H)
#define BASEMENT_SCENE_H

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

const int mapdata_basement_layer1[] = {
467,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,467,
467,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,467,
467,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,467,
475,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,475,

};
const int mapdata_basement_layer2[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,923,924,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,931,932,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,618,-1,-1,-1,618,-1,-1,-1,487,487,-1,-1,618,-1,-1,-1,
-1,-1,939,940,-1,-1,-1,-1,-1,-1,-1,-1,495,495,-1,-1,-1,-1,-1,-1,
-1,-1,947,948,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,876,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,859,-1,
-1,343,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,859,-1,859,-1,-1,
-1,351,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,869,951,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,859,-1,868,951,-1,869,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

Tilemap tilemap_basement_layer1;
Tilemap tilemap_basement_layer2;



// InteractPoint point_to_basement;
// const char* point_to_basement_label = "Enter";
// void point_to_basement_interact(InteractPoint* self){
//     GameServer_load_scene(game_server, &scene_basement);
// }



void scene_basement_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 1, 7);

    // setup interact points
    // game_server->interact_points[0] = &point_to_basement;
    // game_server->interact_points[1] = &point_bulleitin_board;
}


void init_scene_basement()
{
    // tilemap layers
    tilemap_basement_layer1.tileset = &simple_set;
    tilemap_basement_layer1.map_data = mapdata_basement_layer1;
    tilemap_basement_layer1.w = 20;
    tilemap_basement_layer1.h = 14;

    tilemap_basement_layer2.tileset = &simple_set;
    tilemap_basement_layer2.map_data = mapdata_basement_layer2;
    tilemap_basement_layer2.w = 20;
    tilemap_basement_layer2.h = 14;

    // scene
    Scene_new(&scene_basement); // clear init memory
    scene_basement.map_layers[0] = &tilemap_basement_layer1;
    scene_basement.map_layers[1] = &tilemap_basement_layer2;
    scene_basement.ambient_color = WHITE;
    scene_basement.setup = scene_basement_setup;

    // interact points
    // point_to_basement.action_name_str = point_to_basement_label;
    // point_to_basement.interact = point_to_basement_interact;
    // point_to_basement.x = 6;
    // point_to_basement.y = 7;

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

#endif // BASEMENT_SCENE_H
