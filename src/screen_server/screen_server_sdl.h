#if !defined(SCREEN_SERVER_SDL_H)
#define SCREEN_SERVER_SDL_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL.h>

#include "../const.h"
#include "screen_server.h"


typedef struct
{
    ScreenServer base;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    uint32_t last_filp_time;
} ScreenServerSDL;


ScreenServerSDL* ScreenServerSDL_new(ScreenServerSDL* self);
void ScreenServerSDL_init(ScreenServerSDL* self);
void ScreenServerSDL_stop(ScreenServerSDL* self);
void ScreenServerSDL_draw_pixel(ScreenServerSDL* self, int x, int y, short color);
void ScreenServerSDL_flip(ScreenServerSDL* self);


#endif // SCREEN_SERVER_SDL_H

