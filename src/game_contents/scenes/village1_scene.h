#if !defined(VILLAGE1_SCENE_H)
#define VILLAGE1_SCENE_H

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
#include "../farmer.h"

const int mapdata_village1_layer1[] = {
565,565,565,0,0,0,0,566,566,566,566,566,0,0,0,560,560,560,560,560,
573,573,573,0,0,0,0,574,574,574,574,574,0,0,0,568,568,568,568,568,
581,581,581,0,0,0,0,582,582,582,582,582,0,0,0,576,576,576,576,576,
589,589,589,0,0,0,0,590,590,590,590,590,0,0,0,584,584,584,584,584,
464,465,466,0,0,0,0,353,353,353,353,353,0,0,0,368,369,369,369,370,
472,473,474,0,0,0,0,361,361,361,361,361,0,0,0,376,377,377,377,378,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
const int mapdata_village1_layer2[] = {
-1,-1,-1,44,-1,176,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,44,176,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,176,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,-1,-1,-1,-1,
-1,-1,-1,42,-1,176,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,-1,-1,-1,-1,
-1,611,-1,-1,-1,176,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,593,-1,593,-1,
-1,619,-1,-1,-1,176,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,601,-1,601,-1,
51,-1,164,-1,-1,185,-1,-1,-1,-1,-1,-1,-1,143,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,147,148,148,148,148,148,148,148,148,148,148,148,148,148,148,
42,-1,-1,-1,235,177,-1,-1,-1,-1,-1,-1,229,-1,143,-1,-1,-1,-1,-1,
46,47,-1,-1,-1,176,152,153,154,152,153,154,237,-1,143,-1,-1,-1,928,929,
-1,-1,-1,-1,-1,176,160,161,162,160,161,162,230,231,143,875,875,-1,936,937,
14,15,-1,43,-1,176,168,169,170,168,169,170,238,239,143,888,889,-1,944,945,
22,39,15,-1,-1,176,-1,-1,-1,-1,-1,-1,-1,-1,151,896,897,866,-1,-1,
-1,22,23,-1,45,186,184,184,184,184,184,184,184,184,184,184,184,184,184,184,
};
const int mapdata_village1_layer3[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,12,13,-1,-1,-1,158,158,158,167,167,159,-1,-1,-1,-1,-1,-1,-1,-1,
-1,20,21,-1,-1,-1,158,158,158,159,167,167,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,158,158,158,159,159,159,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,12,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};
const int mapdata_village1_layer4[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,246,247,262,263,278,279,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,254,255,270,271,286,287,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,155,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,163,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

Tilemap tilemap_village1_layer1;
Tilemap tilemap_village1_layer2;
Tilemap tilemap_village1_layer3;
Tilemap tilemap_village1_layer4;



Dialog dialog_farmer;
char* dialog_farmer_text = "I've never seen you before. Welcome to our village.";
char* dialog_farmer_choice1 = "F: Where I'm I?";
char* dialog_farmer_choice2 = "G: Have a nice day.";

Dialog dialog_farmer_1;
char* dialog_farmer_1_text = "\
Sorry, I've never left this village so I don't\n\
know. If you are looking for hotel, keep walking\n\
and you will see one. They may be able to answer\n\
your question.";
char* dialog_farmer_1_choice1 = "F: Thank you";

InteractPoint point_farmer;
const char* point_farmer_label = "Talk";
void point_farmer_interact(InteractPoint* self){
    GameServer_set_dialog(game_server, &dialog_farmer);
}


Dialog dialog_bulletin_board;
char* dialog_bulletin_board_text = "\
Urgent: Soldiers needed. Please contact any border\n\
post if interested.";
char* dialog_bulletin_board_choice1 = "F: Close";

InteractPoint point_bulleitin_board;
const char* point_bulleitin_board_label = "Bulleitin Board";
void point_bulleitin_board_interact(InteractPoint* self){
    GameServer_set_dialog(game_server, &dialog_bulletin_board);
}

InteractPoint point_to_right_village;
const char* point_to_right_village_label = "Keep going";
void point_to_right_village_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_village2);
}



void scene_village1_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 1, 6);

    // setup NPC
    game_server->actor_list[1] = &actor_farmer;
    actor_farmer.set_position(&actor_farmer, 8, 8);

    // setup interact points
    game_server->interact_points[0] = &point_farmer;
    game_server->interact_points[1] = &point_bulleitin_board;
    game_server->interact_points[2] = &point_to_right_village;
}


void init_scene_village1()
{
    // tilemap layers
    tilemap_village1_layer1.tileset = &simple_set;
    tilemap_village1_layer1.map_data = mapdata_village1_layer1;
    tilemap_village1_layer1.w = 20;
    tilemap_village1_layer1.h = 14;

    tilemap_village1_layer2.tileset = &simple_set;
    tilemap_village1_layer2.map_data = mapdata_village1_layer2;
    tilemap_village1_layer2.w = 20;
    tilemap_village1_layer2.h = 14;

    tilemap_village1_layer3.tileset = &simple_set;
    tilemap_village1_layer3.map_data = mapdata_village1_layer3;
    tilemap_village1_layer3.w = 20;
    tilemap_village1_layer3.h = 14;

    tilemap_village1_layer4.tileset = &simple_set;
    tilemap_village1_layer4.map_data = mapdata_village1_layer4;
    tilemap_village1_layer4.w = 20;
    tilemap_village1_layer4.h = 14;

    // scene
    Scene_new(&scene_village1); // clear init memory
    scene_village1.map_layers[0] = &tilemap_village1_layer1;
    scene_village1.map_layers[1] = &tilemap_village1_layer2;
    scene_village1.map_layers[2] = &tilemap_village1_layer3;
    scene_village1.map_layers[3] = &tilemap_village1_layer4;
    scene_village1.ambient_color = WHITE;
    scene_village1.setup = scene_village1_setup;

    // interact points
    point_farmer.action_name_str = point_farmer_label;
    point_farmer.interact = point_farmer_interact;
    point_farmer.x = 8;
    point_farmer.y = 7;

    point_bulleitin_board.action_name_str = point_bulleitin_board_label;
    point_bulleitin_board.interact = point_bulleitin_board_interact;
    point_bulleitin_board.x = 13;
    point_bulleitin_board.y = 9;

    point_to_right_village.action_name_str = point_to_right_village_label;
    point_to_right_village.interact = point_to_right_village_interact;
    point_to_right_village.x = 19;
    point_to_right_village.y = 7;

    // dialog
    Dialog_new(&dialog_farmer);
    dialog_farmer.text = dialog_farmer_text;
    dialog_farmer.choice1 = dialog_farmer_choice1;
    dialog_farmer.choice2 = dialog_farmer_choice2;
    dialog_farmer.next1 = &dialog_farmer_1;
    Dialog_new(&dialog_farmer_1);
    dialog_farmer_1.text = dialog_farmer_1_text;
    dialog_farmer_1.choice1 = dialog_farmer_1_choice1;

    Dialog_new(&dialog_bulletin_board);
    dialog_bulletin_board.text = dialog_bulletin_board_text;
    dialog_bulletin_board.choice1 = dialog_bulletin_board_choice1;
}

#endif // village1_SCENE_H
