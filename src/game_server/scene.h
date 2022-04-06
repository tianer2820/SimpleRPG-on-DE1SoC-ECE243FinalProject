#if !defined(SCENE_H)
#define SCENE_H

#include <stdlib.h>

#include "../screen_server/screen_server.h"
#include "../paint_functions.h"
#include "../const.h"
#include "../tilemap/tilemap.h"

#define SCENE_MAP_LAYERS_MAX 4

typedef struct SceneStruct
{
    Tilemap* map_layers[SCENE_MAP_LAYERS_MAX];
    short ambient_color;
    void (*setup)(struct SceneStruct* self);
} Scene;


void Scene_draw_map(Scene* self, ScreenServer* server, int x, int y){
    int i;
    for (i = 0; i < SCENE_MAP_LAYERS_MAX; i++)
    {
        Tilemap* map = self->map_layers[i];
        if(map == NULL){
            break;
        }
        // draw map
        if (self->ambient_color ==  0xFFFF) // save some cpu if no ambient color change
        {
            Tilemap_draw_map(map, server, x, y);
        }
        else{
            Tilemap_draw_map_color(map, server, x, y, self->ambient_color);
        }
    }
    
}

Scene* Scene_new(Scene* self){
    int i;
    for (i = 0; i < SCENE_MAP_LAYERS_MAX; i++)
    {
        self->map_layers[i] = NULL;
    }
    self->ambient_color = 0xFFFF;
}

bool Scene_tile_is_solid(Scene* self, unsigned int x, unsigned int y){
    int i;
    for (i = 0; i < SCENE_MAP_LAYERS_MAX; i++)
    {
        if (self->map_layers[i] == NULL)
        {
            break;
        }
        if (Tilemap_tile_is_solid(self->map_layers[i], x, y)){
            return true;
        }
    }
    return false;
}

#endif // SCENE_H
