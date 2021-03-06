#if !defined(GAME_CONTENTS_H)
#define GAME_CONTENTS_H

#include "resources.h"
#include "tilesets.h"

#include "player.h"
#include "farmer.h"
#include "servant.h"
#include "hex_display.h"
#include "weapon.h"
#include "monster.h"

#include "scenes/scenes_globals.h"
#include "scenes/initial_scene.h"
#include "scenes/hallway_scene.h"
#include "scenes/village1_scene.h"
#include "scenes/village2_scene.h"
#include "scenes/ruins_scene.h"
#include "scenes/basement_scene.h"

/* all in one place to init game contents. */
void init_game_contents(){
    init_tilesets();
    
    init_player();
    init_farmer();
    init_servant();
    init_hex();
    init_weapon();
    init_monster();

    init_scene_initial();
    init_scene_hallway();
    init_scene_village1();
    init_scene_village2();
    init_scene_ruins();
    init_scene_basement();
}


#endif // GAME_CONTENTS_H
