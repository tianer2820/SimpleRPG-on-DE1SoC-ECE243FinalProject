#if !defined(TILEMAP_H)
#define TILEMAP_H

#include <stdlib.h>

#include "tileset.h"
#include "../screen_server/screen_server.h"

typedef struct
{
    Tileset* tileset;
    const int* map_data;
    unsigned int w;
    unsigned int h;
} Tilemap;


void Tilemap_draw_map(Tilemap* map, ScreenServer* server, int x, int y);
void Tilemap_draw_map_color(Tilemap* map, ScreenServer* server, int x, int y, short color);

int Tilemap_id_at_tile(Tilemap* self, unsigned int x, unsigned int y);
bool Tilemap_tile_is_solid(Tilemap* self, unsigned int x, unsigned int y);

#endif // TILEMAP_H
