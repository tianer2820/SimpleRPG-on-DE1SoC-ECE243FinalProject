#if !defined(UTILS_H)
#define UTILS_H

#include "const.h"

short rgb2short(unsigned char r, unsigned char g, unsigned char b);
void short2rgb(short color, unsigned char* r, unsigned char* g, unsigned char* b);

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// simple data types
typedef struct{
    int x;
    int y;
    int w;
    int h;
} Rect2D;

bool pos_in_rect(int x, int y, Rect2D rect);
bool rect_overlaps(Rect2D rect1, Rect2D rect2);

#endif // UTILS_H
