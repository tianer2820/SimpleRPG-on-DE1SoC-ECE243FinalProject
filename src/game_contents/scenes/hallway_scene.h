#if !defined(HALLWAY_SCENE_H)
#define HALLWAY_SCENE_H

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

const int mapdata_hallway_layer1[] = {
    308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,
    308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,
    308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,
    449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,
    449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,
    457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,
    297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,350,
    297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,297,350,
    449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,
    449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,449,
    457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,457,
    308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,
    308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,
    308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,
};
const int mapdata_hallway_layer2[] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,
    439,-1,-1,-1,-1,-1,-1,627,-1,439,-1,-1,-1,626,-1,-1,-1,-1,439,-1,
    447,-1,-1,-1,-1,-1,-1,635,-1,447,-1,-1,-1,634,-1,-1,-1,-1,447,342,
    50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,-1,342,
    -1,51,-1,51,-1,-1,-1,50,-1,-1,51,-1,-1,-1,-1,60,51,51,-1,-1,
    454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,454,
    519,519,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    527,527,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};


Tilemap tilemap_hallway_layer1;
Tilemap tilemap_hallway_layer2;


InteractPoint point_back_to_initial;
const char* point_back_to_initial_label = "To lecture room";
void point_back_to_initital_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_initial);
    GameServer_move_player(game_server, 2, 2);
}

InteractPoint point_to_outside1;
InteractPoint point_to_outside2;
const char* point_to_outside_label = "To outside";
void point_to_outside_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_village1);
    GameServer_move_player(game_server, 1, 6);
}


void scene_hallway_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 0, 7);

    // setup interact points
    game_server->interact_points[0] = &point_back_to_initial;
    game_server->interact_points[1] = &point_to_outside1;
    game_server->interact_points[2] = &point_to_outside2;
}


void init_scene_hallway()
{
    // tilemap layers
    tilemap_hallway_layer1.tileset = &simple_set;
    tilemap_hallway_layer1.map_data = mapdata_hallway_layer1;
    tilemap_hallway_layer1.w = 20;
    tilemap_hallway_layer1.h = 14;

    tilemap_hallway_layer2.tileset = &simple_set;
    tilemap_hallway_layer2.map_data = mapdata_hallway_layer2;
    tilemap_hallway_layer2.w = 20;
    tilemap_hallway_layer2.h = 14;

    // scene
    Scene_new(&scene_hallway); // clear init memory
    scene_hallway.map_layers[0] = &tilemap_hallway_layer1;
    scene_hallway.map_layers[1] = &tilemap_hallway_layer2;
    scene_hallway.ambient_color = 0x7BCF;
    scene_hallway.setup = scene_hallway_setup;

    // interact points
    point_back_to_initial.action_name_str = point_back_to_initial_label;
    point_back_to_initial.interact = point_back_to_initital_interact;
    point_back_to_initial.x = 1;
    point_back_to_initial.y = 7;

    point_to_outside1.action_name_str = point_to_outside_label;
    point_to_outside1.interact = point_to_outside_interact;
    point_to_outside1.x = 18;
    point_to_outside1.y = 6;
    point_to_outside2.action_name_str = point_to_outside_label;
    point_to_outside2.interact = point_to_outside_interact;
    point_to_outside2.x = 18;
    point_to_outside2.y = 7;
}

#endif // HALLWAY_SCENE_H
