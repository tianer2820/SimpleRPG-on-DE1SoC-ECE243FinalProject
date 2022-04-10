#if !defined(TEMPLATE_SCENE_H)
#define TEMPLATE_SCENE_H

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

const int mapdata_TEMPLATE_layer1[] = {
    0, 0, 0, 0, 0, 0,
};
const int mapdata_TEMPLATE_layer2[] = {
    0, 0, 0, 0, 0, 0,
};
const int mapdata_TEMPLATE_layer3[] = {
    0, 0, 0, 0, 0, 0,
};
const int mapdata_TEMPLATE_layer4[] = {
    0, 0, 0, 0, 0, 0,
};

Tilemap tilemap_TEMPLATE_layer1;
Tilemap tilemap_TEMPLATE_layer2;
Tilemap tilemap_TEMPLATE_layer3;
Tilemap tilemap_TEMPLATE_layer4;

InteractPoint point_TEMPLATE;
const char* point_TEMPLATE_label = "To lecture room";
void point_back_to_initital_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_TEMPLATE);
    GameServer_move_player(game_server, 0, 0);
}

Scene scene_TEMPLATE; // add this line to scenes_globals.h
void scene_TEMPLATE_setup(Scene *self)
{
    // setup player
    game_server->actor_list[0] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 0, 0);

    // setup NPC
    // add npc here..

    // setup interact points
    game_server->interact_points[0] = &point_TEMPLATE;
}


void init_scene_TEMPLATE()
{
    // tilemap layers
    tilemap_TEMPLATE_layer1.tileset = &simple_set;
    tilemap_TEMPLATE_layer1.map_data = mapdata_TEMPLATE_layer1;
    tilemap_TEMPLATE_layer1.w = 20;
    tilemap_TEMPLATE_layer1.h = 14;

    tilemap_TEMPLATE_layer2.tileset = &simple_set;
    tilemap_TEMPLATE_layer2.map_data = mapdata_TEMPLATE_layer2;
    tilemap_TEMPLATE_layer2.w = 20;
    tilemap_TEMPLATE_layer2.h = 14;

    // scene
    Scene_new(&scene_TEMPLATE); // clear init memory
    scene_TEMPLATE.map_layers[0] = &tilemap_TEMPLATE_layer1;
    scene_TEMPLATE.map_layers[1] = &tilemap_TEMPLATE_layer2;
    scene_TEMPLATE.ambient_color = 0x7BCF;
    scene_TEMPLATE.setup = scene_TEMPLATE_setup;

    // interact points
    point_TEMPLATE.action_name_str = point_TEMPLATE_label;
    point_TEMPLATE.interact = point_back_to_initital_interact;
    point_TEMPLATE.x = 1;
    point_TEMPLATE.y = 7;
}

#endif // TEMPLATE_SCENE_H
