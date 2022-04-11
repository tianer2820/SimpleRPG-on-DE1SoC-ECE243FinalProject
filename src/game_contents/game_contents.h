#if !defined(GAME_CONTENTS_H)
#define GAME_CONTENTS_H

#include "resources.h"
#include "tilesets.h"
#include "player.h"
#include "farmer.h"

#include "scenes/scenes_globals.h"
#include "scenes/initial_scene.h"
#include "scenes/hallway_scene.h"
#include "scenes/village1_scene.h"

/* all in one place to init game contents. */
void init_game_contents(){
    init_tilesets();
    init_scene_initial();
    init_scene_hallway();
    init_scene_village1();

    
    init_player();
    init_farmer();
}


#endif // GAME_CONTENTS_H
