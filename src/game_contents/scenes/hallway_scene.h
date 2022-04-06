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
// const int mapdata_hallway_layer3[] = {
// };
// const int mapdata_hallway_layer4[] = {
// };

Tilemap tilemap_hallway_layer1;
Tilemap tilemap_hallway_layer2;
// Tilemap tilemap_hallway_layer3;
// Tilemap tilemap_hallway_layer4;



void scene_hallway_setup(Scene *self)
{
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    // move player to spawn point
    actor_player.base.block_x = 0;
    actor_player.base.block_y = 7;
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

    // scene object
    Scene_new(&scene_hallway); // clear init memory
    scene_hallway.map_layers[0] = &tilemap_hallway_layer1;
    scene_hallway.map_layers[1] = &tilemap_hallway_layer2;
    scene_hallway.ambient_color = 0x7BCF;
    // scene object functions
    scene_hallway.setup = scene_hallway_setup;

    // interact points

}

#endif // HALLWAY_SCENE_H
