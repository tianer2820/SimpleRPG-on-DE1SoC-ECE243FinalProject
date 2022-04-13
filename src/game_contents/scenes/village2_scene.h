#if !defined(VILLAGE2_SCENE_H)
#define VILLAGE2_SCENE_H

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

const int mapdata_village2_layer1[] = {
0,563,563,563,563,563,563,563,563,563,563,563,0,0,0,0,0,0,0,0,
0,571,571,571,571,571,571,571,571,571,571,571,0,0,0,0,0,0,0,4,
0,579,579,579,579,579,579,579,579,579,579,579,0,0,0,0,0,0,0,4,
0,587,587,587,587,587,587,587,587,587,587,587,0,0,0,0,0,0,4,4,
0,512,513,513,513,513,513,513,513,513,513,514,0,0,0,0,0,0,4,4,
0,520,521,521,521,521,521,521,521,521,521,522,0,0,0,0,0,0,4,4,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,
0,0,0,562,562,562,562,562,562,562,562,562,562,0,0,0,0,0,4,4,
0,0,0,570,570,570,570,570,570,570,570,570,570,0,0,0,0,0,4,4,
0,0,0,578,578,578,578,578,578,578,578,578,578,0,0,0,0,0,4,4,
0,0,0,586,586,586,586,586,586,586,586,586,586,0,0,0,0,0,0,4,
0,0,0,456,457,457,457,457,457,457,457,457,458,0,0,0,0,0,0,4,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
};
const int mapdata_village2_layer2[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,-1,176,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,172,-1,-1,176,-1,-1,-1,
-1,-1,-1,-1,-1,591,-1,-1,-1,-1,-1,-1,53,-1,172,-1,176,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,53,-1,176,-1,-1,906,
-1,-1,503,503,-1,595,-1,595,-1,595,-1,-1,-1,-1,172,-1,176,-1,-1,914,
-1,-1,511,511,-1,603,-1,603,-1,603,-1,-1,-1,172,-1,-1,176,-1,-1,922,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,53,185,-1,-1,-1,
148,148,148,148,148,148,148,148,148,148,148,148,148,148,148,148,148,148,148,148,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,177,-1,914,859,
930,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,761,-1,-1,176,-1,922,-1,
938,-1,-1,-1,591,-1,-1,591,-1,-1,591,-1,-1,-1,764,-1,176,-1,-1,-1,
946,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,761,-1,176,-1,-1,859,
-1,-1,-1,-1,-1,616,-1,-1,616,-1,-1,616,-1,-1,-1,-1,176,-1,-1,-1,
184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,187,-1,-1,-1,
};
const int mapdata_village2_layer3[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,134,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,865,142,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,150,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,906,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,134,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,142,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,150,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,15,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,23,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

Tilemap tilemap_village2_layer1;
Tilemap tilemap_village2_layer2;
Tilemap tilemap_village2_layer3;



// Dialog dialog_farmer;
// char* dialog_farmer_text = "I've never seen you before. Welcome to our village.";
// char* dialog_farmer_choice1 = "F: Where I'm I?";
// char* dialog_farmer_choice2 = "G: Have a nice day.";

// Dialog dialog_farmer_1;
// char* dialog_farmer_1_text = "\
// Sorry, I've never left this village so I don't\n\
// know. If you are looking for hotel, keep walking\n\
// and you will see one. They may be able to answer\n\
// your question.";
// char* dialog_farmer_1_choice1 = "F: Thank you";

// InteractPoint point_farmer;
// const char* point_farmer_label = "Talk";
// void point_farmer_interact(InteractPoint* self){
//     GameServer_set_dialog(game_server, &dialog_farmer);
// }


// Dialog dialog_bulletin_board;
// char* dialog_bulletin_board_text = "\
// Urgent: Soldiers needed. Please contact any border\n\
// post if interested.";
// char* dialog_bulletin_board_choice1 = "F: Close";

// InteractPoint point_bulleitin_board;
// const char* point_bulleitin_board_label = "Bulleitin Board";
// void point_bulleitin_board_interact(InteractPoint* self){
//     GameServer_set_dialog(game_server, &dialog_bulletin_board);
// }

// InteractPoint point_to_right_village;
// const char* point_to_right_village_label = "Keep going";
// void point_to_right_village_interact(InteractPoint* self){
//     GameServer_load_scene(game_server, &scene_village2);
    
// }



void scene_village2_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 1, 6);

    // setup NPC
    game_server->actor_list[1] = &actor_farmer;
    actor_farmer.set_position(&actor_farmer, 8, 8);

    // setup interact points
    // game_server->interact_points[0] = &point_farmer;
    // game_server->interact_points[1] = &point_bulleitin_board;
}


void init_scene_village2()
{
    // tilemap layers
    tilemap_village2_layer1.tileset = &simple_set;
    tilemap_village2_layer1.map_data = mapdata_village2_layer1;
    tilemap_village2_layer1.w = 20;
    tilemap_village2_layer1.h = 14;

    tilemap_village2_layer2.tileset = &simple_set;
    tilemap_village2_layer2.map_data = mapdata_village2_layer2;
    tilemap_village2_layer2.w = 20;
    tilemap_village2_layer2.h = 14;

    tilemap_village2_layer3.tileset = &simple_set;
    tilemap_village2_layer3.map_data = mapdata_village2_layer3;
    tilemap_village2_layer3.w = 20;
    tilemap_village2_layer3.h = 14;

    // scene
    Scene_new(&scene_village2); // clear init memory
    scene_village2.map_layers[0] = &tilemap_village2_layer1;
    scene_village2.map_layers[1] = &tilemap_village2_layer2;
    scene_village2.map_layers[2] = &tilemap_village2_layer3;
    scene_village2.ambient_color = WHITE;
    scene_village2.setup = scene_village2_setup;

    // interact points
    // point_farmer.action_name_str = point_farmer_label;
    // point_farmer.interact = point_farmer_interact;
    // point_farmer.x = 8;
    // point_farmer.y = 7;

    // point_bulleitin_board.action_name_str = point_bulleitin_board_label;
    // point_bulleitin_board.interact = point_bulleitin_board_interact;
    // point_bulleitin_board.x = 13;
    // point_bulleitin_board.y = 9;

    // dialog
    // Dialog_new(&dialog_farmer);
    // dialog_farmer.text = dialog_farmer_text;
    // dialog_farmer.choice1 = dialog_farmer_choice1;
    // dialog_farmer.choice2 = dialog_farmer_choice2;
    // dialog_farmer.next1 = &dialog_farmer_1;
    // Dialog_new(&dialog_farmer_1);
    // dialog_farmer_1.text = dialog_farmer_1_text;
    // dialog_farmer_1.choice1 = dialog_farmer_1_choice1;

    // Dialog_new(&dialog_bulletin_board);
    // dialog_bulletin_board.text = dialog_bulletin_board_text;
    // dialog_bulletin_board.choice1 = dialog_bulletin_board_choice1;
}

#endif // VILLAGE2_SCENE_H
