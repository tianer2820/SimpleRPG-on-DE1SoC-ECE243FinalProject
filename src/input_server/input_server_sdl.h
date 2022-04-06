#if !defined(INPUT_SERVER_SDL_H)
#define INPUT_SERVER_SDL_H

#include <stdlib.h>

#include <SDL.h>

#include "input_server.h"

typedef struct
{
    InputServer base;
} InputServerSDL;


void InputServerSDL_init(InputServerSDL *self) {}
void InputServerSDL_update(InputServerSDL *self) {}
void InputServerSDL_stop(InputServerSDL *self) {}
bool InputServerSDL_key_is_pressed(InputServerSDL *self, KeyScancode key)
{
    int n;
    const unsigned char *key_states = SDL_GetKeyboardState(&n);
    if (key >= n)
        return false;
    return (bool)key_states[key];
}




InputServerSDL *InputServerSDL_new(InputServerSDL *self)
{
    InputServerSDL *server = self;
    if (server == NULL)
    {
        server = (InputServerSDL *)calloc(1, sizeof(InputServerSDL));
    }
    InputServer_new(server);
    server->base.init = InputServerSDL_init;
    server->base.update = InputServerSDL_update;
    server->base.stop = InputServerSDL_stop;
    server->base.key_is_pressed = InputServerSDL_key_is_pressed;
    return server;
}




#endif // INPUT_SERVER_SDL_H
