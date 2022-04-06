#if !defined(TILESET_H)
#define TILESET_H


#include <stdlib.h>

#include "../const.h"
#include "../images/short_image.h"
#include "../images/image_slice.h"


typedef struct
{
    ShortImage img;
    unsigned int tile_size;
    unsigned int w;
    unsigned int h;
    const unsigned char* solid_mask;
} Tileset;

ImageSlice Tileset_get_tile(Tileset* self, int tile_id);
bool Tileset_is_solid(Tileset* self, int tile_id);


#endif // TILESET_H
