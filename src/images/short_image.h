#if !defined(SHORT_IMAGE_H)
#define SHORT_IMAGE_H

#include <stdio.h>

typedef struct ShortImageStruct
{
    unsigned int w;
    unsigned int h;
    const unsigned short* data;
    const unsigned char* mask;
} ShortImage;


ShortImage* ShortImage_new(ShortImage* self);

#endif // SHORT_IMAGE_H



