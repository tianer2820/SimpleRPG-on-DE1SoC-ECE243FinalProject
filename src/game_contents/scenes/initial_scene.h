#if !defined(MAPS_H)
#define MAPS_H

#include <stdlib.h>
#include "../../globals.h"
#include "scenes_globals.h"

#include "../../images/short_image.h"
#include "../../tilemap/tilemap.h"
#include "../../tilemap/tileset.h"
#include "../../game_server/scene.h"
#include "../../game_server/interact_point.h"
#include "../../game_server/dialog.h"

#include "../resources.h"
#include "../tilesets.h"
#include "../player.h"



const int mapdata_initial_layer1[] = {
    451,449,449,449,449,308,308,308,308,308,308,308,308,308,308,449,449,449,449,451,
    451,457,457,457,457,308,308,308,308,308,308,308,308,308,308,457,457,457,457,451,
    451,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,451,
    451,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,451,
    451,348,340,677,678,678,678,678,678,678,678,678,678,678,678,678,679,348,340,451,
    451,348,340,297,297,297,297,297,297,297,297,297,297,297,297,297,297,348,340,451,
    451,348,340,677,678,678,678,678,678,678,678,678,678,678,678,678,679,348,340,451,
    451,348,340,297,297,297,297,297,297,297,297,297,297,297,297,297,297,348,340,451,
    451,348,340,677,678,678,678,678,678,678,678,678,678,678,678,678,679,348,340,451,
    451,348,340,297,297,297,297,297,297,297,297,297,297,297,297,297,297,348,340,451,
    451,348,340,677,678,678,678,678,678,678,678,678,678,678,678,678,679,348,340,451,
    451,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,451,
    451,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,451,
    459,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,459,
};
const int mapdata_initial_layer2[] = {
    -1,519,519,-1,-1,-1,626,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,519,519,-1,
    -1,527,527,-1,-1,-1,634,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,527,527,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,848,849,849,850,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,977,-1,-1,-1,-1,978,-1,-1,-1,-1,
    -1,-1,-1,754,754,754,754,754,754,754,754,754,754,754,754,754,754,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,754,754,754,754,754,754,754,754,754,754,754,754,754,754,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,976,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,754,754,754,754,754,754,754,754,754,754,754,754,754,754,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,957,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,754,754,754,754,754,754,754,754,754,754,754,754,754,754,-1,-1,-1,
    -1,519,519,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,519,519,-1,
    -1,527,527,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,527,527,-1,
};
Tilemap tilemap_initial_layer1;
Tilemap tilemap_initial_layer2;

// interact points
InteractPoint point_front_door;
const char* point_front_door_label = "Into hallway";
void point_frontdoor_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_hallway);
}


Dialog dialog_new_book;
char* dialog_new_book_text = "\
Lecture Notes 37\n\
Associative Cache Architecture\n\
......";
char* dialog_new_book_choice1 = "F: Close";
InteractPoint point_new_book;
const char* point_new_book_label = "Read";
void point_new_book_interact(InteractPoint* self){
    GameServer_set_dialog(game_server, &dialog_new_book);
}


Dialog dialog_old_paper1;
Dialog dialog_old_paper2;
char* dialog_old_paper_text1 = "\
This is our third attempt on this dungeon. We\n\
finally came to the bottom this time. With no luck,\n\
we found nothing here except books with symbols we";
char* dialog_old_paper_text2 = "\
can't read. We are taking them back anyway. Maybe\n\
they worth something.";
char* dialog_old_paper_choice1 = "F: Continue";
char* dialog_old_paper_choice2 = "F: Close";

InteractPoint point_old_paper;
const char* point_old_paper_label = "Read";
void point_old_paper_interact(InteractPoint* self){
    GameServer_set_dialog(game_server, &dialog_old_paper1);
}


void scene_initial_setup(Scene* self){
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 7, 11);
    // add interact points
    game_server->interact_points[0] = &point_front_door;
    game_server->interact_points[1] = &point_new_book;
    game_server->interact_points[2] = &point_old_paper;

}


void init_scene_initial(){
    // tilemap layers
    tilemap_initial_layer1.tileset = &simple_set;
    tilemap_initial_layer1.map_data = mapdata_initial_layer1;
    tilemap_initial_layer1.w = 20;
    tilemap_initial_layer1.h = 14;

    tilemap_initial_layer2.tileset = &simple_set;
    tilemap_initial_layer2.map_data = mapdata_initial_layer2;
    tilemap_initial_layer2.w = 20;
    tilemap_initial_layer2.h = 14;

    // scene object
    Scene_new(&scene_initial); // clear init memory
    scene_initial.map_layers[0] = &tilemap_initial_layer1;
    scene_initial.map_layers[1] = &tilemap_initial_layer2;
    scene_initial.ambient_color = 0x7BCF;
    // scene object functions
    scene_initial.setup = scene_initial_setup;

    // interact points
    point_front_door.x = 2;
    point_front_door.y = 2;
    point_front_door.action_name_str = point_front_door_label;
    point_front_door.interact = point_frontdoor_interact;

    point_new_book.x = 6;
    point_new_book.y = 11;
    point_new_book.action_name_str = point_new_book_label;
    point_new_book.interact = point_new_book_interact;
    Dialog_new(&dialog_new_book);
    dialog_new_book.text = dialog_new_book_text;
    dialog_new_book.choice1 = dialog_new_book_choice1;

    point_old_paper.x = 10;
    point_old_paper.y = 9;
    point_old_paper.action_name_str = point_old_paper_label;
    point_old_paper.interact = point_old_paper_interact;
    Dialog_new(&dialog_old_paper1);
    dialog_old_paper1.text = dialog_old_paper_text1;
    dialog_old_paper1.choice1 = dialog_old_paper_choice1;
    dialog_old_paper1.next1 = &dialog_old_paper2;
    Dialog_new(&dialog_old_paper2);
    dialog_old_paper2.text = dialog_old_paper_text2;
    dialog_old_paper2.choice1 = dialog_old_paper_choice2;
}


#endif // MAPS_H
