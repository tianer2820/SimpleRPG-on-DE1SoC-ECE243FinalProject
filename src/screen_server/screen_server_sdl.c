#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL.h>

#include "../const.h"
#include "../utils.h"

#include "screen_server.h"
#include "screen_server_sdl.h"


ScreenServerSDL* ScreenServerSDL_new(ScreenServerSDL* self){
    ScreenServerSDL* server_sdl = self;
    if(server_sdl == NULL){
        server_sdl = calloc(1, sizeof(ScreenServerSDL));
    }
    ScreenServer* server = server_sdl;

    server->init = ScreenServerSDL_init;
    server->stop = ScreenServerSDL_stop;

    server->draw_pixel = ScreenServerSDL_draw_pixel;
    server->flip = ScreenServerSDL_flip;
    return server_sdl;
}

void ScreenServerSDL_init(ScreenServerSDL* self){
    // init
    SDL_Init(SDL_INIT_VIDEO);

    // window, renderer, surface and texture
    self->window = SDL_CreateWindow("My SDL Empty Window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    self->renderer = SDL_CreateRenderer(self->window, -1, 0);
    self->surface = SDL_CreateRGBSurface(0, RESOLUTION_X, RESOLUTION_Y, 32,
            0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
    if (self->surface == NULL)
    {
        printf("Error occured: ");
        printf(SDL_GetError());
    }

    // timming
    self->last_filp_time = SDL_GetTicks();
}

void ScreenServerSDL_stop(ScreenServerSDL* self){
    // quit
    SDL_FreeSurface(self->surface);
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    SDL_Quit();
}

void ScreenServerSDL_draw_pixel(ScreenServerSDL* self, int x, int y, short color){
    // ensure in range
    x = max(0, min(x, RESOLUTION_X - 1));
    y = max(0, min(y, RESOLUTION_Y - 1));

    // convert color
    uint32_t r, g, b;
    r = (color & (0b11111 << 11)) >> 11;
    r = r * 255 / 0b11111;
    g = (color & (0b111111 << 5)) >> 5;
    g = g * 255 / 0b111111;
    b = (color & (0b11111));
    b = b * 255 / 0b11111;


    SDL_Surface* surface = self->surface;
    SDL_LockSurface(surface);

    unsigned int* target_pixel = (uint32_t*)((uint8_t *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);
    *target_pixel = SDL_MapRGB(surface->format, r, g, b);

    SDL_UnlockSurface(surface);
}

void ScreenServerSDL_flip(ScreenServerSDL* self){
    SDL_Texture * texture = SDL_CreateTextureFromSurface(self->renderer, self->surface);

    // keep aspect ratio
    int w, h;
    SDL_GetWindowSize(self->window, &w, &h);
    float w_ratio, h_ratio;
    w_ratio = w / (float)self->surface->w;
    h_ratio = h / (float)self->surface->h;
    float ratio = min(w_ratio, h_ratio);
    SDL_Rect rect;
    rect.w = self->surface->w * ratio;
    rect.h = self->surface->h * ratio;
    rect.x = abs(w - rect.w) / 2;
    rect.y = abs(h - rect.h) / 2;

    SDL_RenderCopy(self->renderer, texture, NULL, &rect);
    SDL_RenderPresent(self->renderer);

    SDL_DestroyTexture(texture);

    uint32_t time = SDL_GetTicks();
    while (time - self->last_filp_time < 17) // lock to 60fps
    {
        SDL_Delay(2);
        time = SDL_GetTicks();
    }
    uint32_t delta = time - self->last_filp_time;
    self->last_filp_time = time - (delta - 17);

}
