#include <stdlib.h>

#include "../images/short_image.h"
#include "../images/image_slice.h"
#include "../tilemap/tileset.h"

ImageSlice Tileset_get_tile(Tileset *self, int tile_id)
{
    if (tile_id == -1)
    {
        ImageSlice empty;
        ImageSlice_new(&empty);
        return empty;
    }

    unsigned int x, y;
    x = tile_id % self->w;
    y = tile_id / self->w;

    ImageSlice slice;
    ImageSlice_new(&slice);
    slice.img = self->img;
    slice.w = self->tile_size;
    slice.h = self->tile_size;
    slice.x = x * self->tile_size;
    slice.y = y * self->tile_size;
    return slice;
}

bool Tileset_is_solid(Tileset *self, int tile_id)
{
    if (tile_id == -1 || self->solid_mask == NULL)
        return false;

    unsigned int byte_offset = tile_id / 8;
    unsigned int bit_offset = 7 - (tile_id % 8);

    return (self->solid_mask[byte_offset] & (1 << bit_offset)) >> bit_offset;
}
