

#include <stdlib.h>
#include "utils.h"

short rgb2short(unsigned char r, unsigned char g, unsigned char b){
    r = r * 0b11111 / 255;
    g = g * 0b111111 / 255;
    b = b * 0b11111 / 255;
    short color = r << 11 | g << 5 | b;
    return color;
}

void short2rgb(short color, unsigned char* r, unsigned char* g, unsigned char* b){
    (*r) = (color & (0b11111 << 11)) >> 11;
    (*r) = (*r) * 255 / 0b11111;
    (*g) = (color & (0b111111 << 5)) >> 5;
    (*g) = (*g) * 255 / 0b111111;
    (*b) = (color & (0b11111));
    (*b) = (*b) * 255 / 0b11111;
}

bool pos_in_rect(int x, int y, Rect2D rect){
    return x >= rect.x && x < rect.x + rect.w &&
           y >= rect.y && y < rect.y + rect.h;
}

bool rect_overlaps(Rect2D rect1, Rect2D rect2){
    return pos_in_rect(rect1.x, rect1.y, rect2) ||
           pos_in_rect(rect1.x + rect1.w, rect1.y, rect2) ||
           pos_in_rect(rect1.x + rect1.w, rect1.y + rect1.h, rect2) ||
           pos_in_rect(rect1.x, rect1.y + rect1.h, rect2) ||

           pos_in_rect(rect2.x, rect2.y, rect1) ||
           pos_in_rect(rect2.x + rect2.w, rect2.y, rect1) ||
           pos_in_rect(rect2.x + rect2.w, rect2.y + rect2.h, rect1) ||
           pos_in_rect(rect2.x, rect2.y + rect2.h, rect1);
}
