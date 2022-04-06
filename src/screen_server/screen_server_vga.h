#if !defined(SCREEN_SERVER_VGA_H)
#define SCREEN_SERVER_VGA_H


#include <stdlib.h>
#include <stdio.h>

#include "../const.h"
#include "screen_server.h"
#include "screen_server_vga.h"

typedef struct
{
    ScreenServer base;
    volatile int _pixel_buffer_start; // global variable
    volatile int *_pixel_ctrl_ptr;
} ScreenServerVGA;

ScreenServerVGA *ScreenServerVGA_new(ScreenServerVGA *self);
void ScreenServerVGA_init(ScreenServerVGA *self);
void ScreenServerVGA_stop(ScreenServerVGA *self);
void ScreenServerVGA_draw_pixel(ScreenServerVGA *self, int x, int y, short int line_color);
void ScreenServerVGA_flip(ScreenServerVGA *self);


#endif // SCREEN_SERVER_VGA_H
