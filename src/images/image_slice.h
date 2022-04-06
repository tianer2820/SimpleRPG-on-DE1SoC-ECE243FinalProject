#if !defined(IMAGE_SLICE_H)
#define IMAGE_SLICE_H

#include <stdlib.h>

#include "short_image.h"
#include "../const.h"

typedef struct
{
    ShortImage img;
    // region
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;
    // render point
    int origin_x;
    int origin_y;
    bool flip_x;
    bool flip_y;
} ImageSlice;


ImageSlice* ImageSlice_new(ImageSlice* self);


#endif // IMAGE_SLICE_H
