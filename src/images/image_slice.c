#include "image_slice.h"
#include <stdlib.h>

#include "short_image.h"


ImageSlice* ImageSlice_new(ImageSlice* self){
    ImageSlice* img = self;
    if(img == NULL){
        img = calloc(1, sizeof(ImageSlice));
    }
    img->x = 0;
    img->y = 0;
    img->w = 0;
    img->h = 0;
    ShortImage_new(&(img->img));
    img->origin_x = 0;
    img->origin_y = 0;
    img->flip_x = false;
    img->flip_y = false;
    return img;
}
