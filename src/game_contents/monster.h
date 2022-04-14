#if !defined(MONSTER_H)
#define MONSTER_H

#include "../globals.h"
#include "../game_server/actor.h"
#include "../anime/anime_player.h"
#include "../images/image_slice.h"
#include "tilesets.h"


Actor actor_monster;

void monster_start(Actor *self)
{
    // nothing
}

void monster_process(Actor *self)
{
    // check player position and start conversation?
    // nothing currently
}


void init_monster()
{
    Actor_new(&actor_monster);
    // actor properties
    actor_monster.id = NPC;
    actor_monster.name = NULL;
    actor_monster.block_x = 0;
    actor_monster.block_y = 0;
    actor_monster.display_x = 0;
    actor_monster.display_y = 0;

    // display
    actor_monster.color = 0xFFFF;
    ImageSlice monster_slice;
    ImageSlice_new(&monster_slice);
    monster_slice.img = monster_img;
    monster_slice.w = monster_img.w;
    monster_slice.h = monster_img.h;
    actor_monster.image = monster_slice;
    actor_monster.image.origin_x = 16;
    actor_monster.image.origin_y = 20;

    // functions
    actor_monster.start = monster_start;
    actor_monster.process = monster_process;
    actor_monster.custom_draw = NULL;
}

#endif // MONSTER_H
