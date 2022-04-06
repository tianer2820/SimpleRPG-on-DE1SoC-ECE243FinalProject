
#include <stdio.h>
#include "short_image.h"



ShortImage* ShortImage_new(ShortImage* self){
    ShortImage* img = self;
    if(img == NULL){
        img = calloc(1, sizeof(ShortImage));
    }
    img->w = 0;
    img->h = 0;
    img->data = NULL;
    img->mask = NULL;
    return img;
}

