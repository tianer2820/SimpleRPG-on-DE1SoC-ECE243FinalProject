#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "const.h"
#include "globals.h"

#include "screen_server/screen_server.h"
#include "input_server/input_server.h"
#ifndef FAKE_SERVER
    #include "screen_server/screen_server_vga.h"
    #include "input_server/input_server_ps2.h"
#else
    #include "screen_server/screen_server_sdl.h"
    #include "input_server/input_server_sdl.h"
#endif

#include "paint_functions.h"
#include "text/textbox.h"

#include "game_server/scene.h"
#include "game_server/game_server.h"
#include "game_contents/game_contents.h"

int main(int argc, char **argv)
{
    // init screen server
    #ifndef FAKE_SERVER
    screen_server = (ScreenServer*)ScreenServerVGA_new(NULL);
    input_server = (InputServer*)InputServerPS2_new(NULL);
    #else
    screen_server = (ScreenServer *)ScreenServerSDL_new(NULL);
    input_server = (InputServer *)InputServerSDL_new(NULL);
    #endif

    screen_server->init(screen_server);
    input_server->init(input_server);

    // init input server

    // init game
    game_server = GameServer_new(NULL);
    GameServer_init(game_server);
    // init game content
    init_game_contents();
    init_scene_initial();
    // GameServer_load_scene(game_server, &scene_hallway);
    GameServer_load_scene(game_server, &scene_initial);

    Dialog initial_dialog;
    Dialog_new(&initial_dialog);
    initial_dialog.text = "You fall asleep in an ECE243 lecture...";
    GameServer_set_dialog(game_server, &initial_dialog);


    bool quit = false;
    while (!quit)
    {
        // event poll if SDL
        #ifdef FAKE_SERVER
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
            // process other events
        }
        #endif

        // input server update
        input_server->update(input_server);

        // game server update
        GameServer_process(game_server);
        GameServer_render(game_server, screen_server);

        // screen server update
        screen_server->flip(screen_server);
    }

    // clean up
    input_server->stop(input_server);
    free(input_server);

    screen_server->stop(screen_server);
    free(screen_server);

    return 0;
}
