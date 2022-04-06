

#include <stdlib.h>


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

