

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
    int rp, gp, bp;
    rp = (color & (0b11111 << 11)) >> 11;
    rp = rp * 255 / 0b11111;
    gp = (color & (0b111111 << 5)) >> 5;
    gp = gp * 255 / 0b111111;
    bp = (color & (0b11111));
    bp = bp * 255 / 0b11111;
    *r = rp;
    *g = gp;
    *b = bp;
}

bool pos_in_rect(int x, int y, Rect2D rect){
    return rect.w != 0 && rect.h != 0 &&
           x >= rect.x && x <= rect.x + rect.w &&
           y >= rect.y && y <= rect.y + rect.h;
}

bool rect_overlaps(Rect2D rect1, Rect2D rect2){
    if(rect1.w == 0 || rect1.h == 0 || rect2.w == 0 || rect2.h == 0)
        return false;
    return pos_in_rect(rect1.x, rect1.y, rect2) ||
           pos_in_rect(rect1.x + rect1.w, rect1.y, rect2) ||
           pos_in_rect(rect1.x + rect1.w, rect1.y + rect1.h, rect2) ||
           pos_in_rect(rect1.x, rect1.y + rect1.h, rect2) ||

           pos_in_rect(rect2.x, rect2.y, rect1) ||
           pos_in_rect(rect2.x + rect2.w, rect2.y, rect1) ||
           pos_in_rect(rect2.x + rect2.w, rect2.y + rect2.h, rect1) ||
           pos_in_rect(rect2.x, rect2.y + rect2.h, rect1);
}
