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
#include "../servant.h"

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



Dialog dialog_servant;
char* dialog_servant_text = "\
Hope this mess will end soon... Oh sorry, welcome,\n\
are you here for a stay?";
char* dialog_servant_choice1 = "F: What happened?";
char* dialog_servant_choice2 = "G: No thanks";

Dialog dialog_servant_1;
char* dialog_servant_1_text = "\
We've been attacked by some monsters recently.\n\
Soldiers are defending this village, but our supply\n\
won't last too long... Everyone is hopping that the\n\
hero will appear again.";
char* dialog_servant_1_choice1 = "F: The hero?";

Dialog dialog_servant_2;
char* dialog_servant_2_text = "\
Yes, long time ago some heros saved the village. It\n\
is said that the person who can solve the spell in\n\
the in the ruins will get their power and become\n\
the next hero.";
char* dialog_servant_2_choice1 = "F: Where is the ruin?";

Dialog dialog_servant_3;
char* dialog_servant_3_text = "\
You want to try? The ruin is at the end of this\n\
road. No one have ever successfully broken the\n\
spell, but if you did, don't forget who pointed you\n\
the way! Wish you the best luck.";
char* dialog_servant_3_choice1 = "F: Thank you";


InteractPoint point_servant;
const char* point_servant_label = "Talk";
void point_servant_interact(InteractPoint* self){
    GameServer_set_dialog(game_server, &dialog_servant);
}




void scene_village2_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 1, 7);

    // setup NPC
    game_server->actor_list[1] = &actor_servant;
    actor_servant.set_position(&actor_servant, 4, 6);

    // setup interact points
    game_server->interact_points[0] = &point_servant;
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
    point_servant.action_name_str = point_servant_label;
    point_servant.interact = point_servant_interact;
    point_servant.x = 4;
    point_servant.y = 7;

    // point_bulleitin_board.action_name_str = point_bulleitin_board_label;
    // point_bulleitin_board.interact = point_bulleitin_board_interact;
    // point_bulleitin_board.x = 13;
    // point_bulleitin_board.y = 9;

    // dialog
    Dialog_new(&dialog_servant);
    dialog_servant.text = dialog_servant_text;
    dialog_servant.choice1 = dialog_servant_choice1;
    dialog_servant.choice2 = dialog_servant_choice2;
    dialog_servant.next1 = &dialog_servant_1;
    Dialog_new(&dialog_servant_1);
    dialog_servant_1.text = dialog_servant_1_text;
    dialog_servant_1.choice1 = dialog_servant_1_choice1;
    dialog_servant_1.next1 = &dialog_servant_2;
    Dialog_new(&dialog_servant_2);
    dialog_servant_2.text = dialog_servant_2_text;
    dialog_servant_2.choice1 = dialog_servant_2_choice1;
    dialog_servant_2.next1 = &dialog_servant_3;
    Dialog_new(&dialog_servant_3);
    dialog_servant_3.text = dialog_servant_3_text;
    dialog_servant_3.choice1 = dialog_servant_3_choice1;

    // Dialog_new(&dialog_bulletin_board);
    // dialog_bulletin_board.text = dialog_bulletin_board_text;
    // dialog_bulletin_board.choice1 = dialog_bulletin_board_choice1;
}

#endif // VILLAGE2_SCENE_H
