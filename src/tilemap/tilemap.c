#include <stdlib.h>

#include "../screen_server/screen_server.h"
#include "../paint_functions.h"
#include "../const.h"
#include "tilemap.h"
#include "tileset.h"


void Tilemap_draw_map(Tilemap* map, ScreenServer* server, int x, int y){
    int tile_x, tile_y, tile_offset_x, tile_offset_y;
    int tile_data_offset;
    ImageSlice slice;

    for ( tile_x = 0; tile_x < map->w; tile_x++)
    {
        for (tile_y = 0; tile_y < map->h; tile_y++)
        {
            tile_offset_x = tile_x * map->tileset->tile_size + x;
            tile_offset_y = tile_y * map->tileset->tile_size + y;
            tile_data_offset = tile_y * map->w + tile_x;

            int id = map->map_data[tile_data_offset];
            if (id == -1) // empty block
            {
                continue;
            }
            slice = Tileset_get_tile(map->tileset, id);
            draw_img_slice(server, tile_offset_x, tile_offset_y, slice);
        }
    }
}

void Tilemap_draw_map_color(Tilemap* map, ScreenServer* server, int x, int y, short color){
    int tile_x, tile_y, tile_offset_x, tile_offset_y;
    int tile_data_offset;
    ImageSlice slice;

    for ( tile_x = 0; tile_x < map->w; tile_x++)
    {
        for (tile_y = 0; tile_y < map->h; tile_y++)
        {
            tile_offset_x = tile_x * map->tileset->tile_size + x;
            tile_offset_y = tile_y * map->tileset->tile_size + y;
            tile_data_offset = tile_y * map->w + tile_x;

            int id = map->map_data[tile_data_offset];
            if (id == -1) // empty block
            {
                continue;
            }
            slice = Tileset_get_tile(map->tileset, id);
            draw_img_slice_color(server, tile_offset_x, tile_offset_y, slice, color);
        }
    }
}

int Tilemap_id_at_tile(Tilemap* self, unsigned int x, unsigned int y){
    if (x < 0 || x >= self->w || y < 0 || y >= self->h)
    {
        return -1;
    }
    
    int tile_offset_x = x * self->tileset->tile_size + x;
    int tile_offset_y = y * self->tileset->tile_size + y;
    int tile_data_offset = y * self->w + x;

    int id = self->map_data[tile_data_offset];
    return id;
}

bool Tilemap_tile_is_solid(Tilemap* self, unsigned int x, unsigned int y){
    if (x < 0 || x >= self->w || y < 0 || y >= self->h)
    {
        return true;
    }
    int id = Tilemap_id_at_tile(self, x, y);
    return Tileset_is_solid(self->tileset, id);
}

