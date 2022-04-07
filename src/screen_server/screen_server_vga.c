#include <stdlib.h>
#include <stdio.h>

#include "../const.h"
#include "../utils.h"
#include "screen_server.h"
#include "screen_server_vga.h"


ScreenServerVGA *ScreenServerVGA_new(ScreenServerVGA *self)
{
    ScreenServerVGA *server_vga = self;
    if (server_vga == NULL)
    {
        server_vga = calloc(1, sizeof(ScreenServerVGA));
    }
    ScreenServer *server = server_vga;

    server->init = ScreenServerVGA_init;
    server->stop = ScreenServerVGA_stop;

    server->draw_pixel = ScreenServerVGA_draw_pixel;
    server->flip = ScreenServerVGA_flip;
    return server_vga;
}

void ScreenServerVGA_init(ScreenServerVGA *self)
{
    ScreenServer *b_self = self;

    self->_pixel_ctrl_ptr = (int *)0xFF203020;

    /* set pixel buffer memory */
    *(self->_pixel_ctrl_ptr + 1) = 0xC8000000;
    b_self->flip((ScreenServer*)self);

    self->_pixel_buffer_start = *(self->_pixel_ctrl_ptr);
    // b_self->fill(self, 0); // clear screen

    *(self->_pixel_ctrl_ptr + 1) = 0xC0000000;
    self->_pixel_buffer_start = *(self->_pixel_ctrl_ptr + 1);
    // b_self->fill(self, 0); // clear screen
}

void ScreenServerVGA_stop(ScreenServerVGA *self)
{
    // nothing todo
}

void ScreenServerVGA_draw_pixel(ScreenServerVGA *self, int x, int y, short int line_color)
{
    // ensure in range
    x = max(0, min(x, RESOLUTION_X - 1));
    y = max(0, min(y, RESOLUTION_Y - 1));
    
    *(short int *)(self->_pixel_buffer_start + (y << 10) + (x << 1)) = line_color;
}

void ScreenServerVGA_flip(ScreenServerVGA *self)
{
    *(self->_pixel_ctrl_ptr) = 1;
    volatile int *status_addr = 0xFF20302C;
    int s = 1;
    while (s)
    {
        s = *status_addr;
        s = s & 1;
    }
    self->_pixel_buffer_start = *(self->_pixel_ctrl_ptr + 1); // new back buffer
}