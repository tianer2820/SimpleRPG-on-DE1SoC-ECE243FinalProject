#if !defined(GAME_CONTENTS_H)
#define GAME_CONTENTS_H

#include "resources.h"
#include "player.h"
#include "scenes/scenes_globals.h"
#include "scenes/initial_scene.h"
#include "scenes/hallway_scene.h"

/* all in one place to init game contents. */
void init_game_contents(){
    init_tilesets();
    init_scene_initial();
    init_scene_hallway();
    init_player();
}


#endif // GAME_CONTENTS_H
