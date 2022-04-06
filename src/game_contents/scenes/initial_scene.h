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

// test interact point
InteractPoint point_test;
const char* point_test_label = "Test Point";

void point_test_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_hallway);
}


void scene_initial_setup(Scene* self){
    game_server->actor_list[0] = &actor_player;
    game_server->player = &actor_player;
    // move player to spawn point
    actor_player.base.block_x = 2;
    actor_player.base.block_y = 2;
    // add test npc
    game_server->interact_points[0] = &point_test;
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
    point_test.x = 2;
    point_test.y = 2;
    point_test.action_name_str = point_test_label;
    point_test.interact = point_test_interact;
}


#endif // MAPS_H
