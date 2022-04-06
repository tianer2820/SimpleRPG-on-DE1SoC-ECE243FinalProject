#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "const.h"
#include "globals.h"

#include "screen_server/screen_server.h"
#include "screen_server/screen_server_sdl.h"

#include "input_server/input_server.h"
#include "input_server/input_server_sdl.h"

#include "paint_functions.h"
#include "text/textbox.h"

#include "game_server/scene.h"
#include "game_server/game_server.h"
#include "game_contents/game_contents.h"



int main(int argc, char ** argv)
{
    // init screen server
    screen_server = (ScreenServer*)ScreenServerSDL_new(NULL);
    screen_server->init(screen_server);

    // init input server
    input_server = (InputServer*)InputServerSDL_new(NULL);
    input_server->init(input_server);

    // init game
    game_server = GameServer_new(NULL);
    GameServer_init(game_server);
    // init game content
    init_game_contents();
    init_scene_initial();
    // GameServer_load_scene(game_server, &scene_hallway);
    GameServer_load_scene(game_server, &scene_initial);

    bool quit = false;
    while (!quit)
    {
        // event poll
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                quit = true;
                break;
            }
            // process other events
        }


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
