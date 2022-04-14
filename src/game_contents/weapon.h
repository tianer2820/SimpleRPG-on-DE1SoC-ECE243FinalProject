#if !defined(WEAPON_H)
#define WEAPON_H

#include "../globals.h"
#include "../game_server/actor.h"
#include "../anime/anime_player.h"
#include "../images/image_slice.h"
#include "tilesets.h"


Actor actor_weapon;

void weapon_start(Actor *self)
{
    // nothing
}

void weapon_process(Actor *self)
{
    // check player position and start conversation?
    // nothing currently
}


void init_weapon()
{
    Actor_new(&actor_weapon);
    // actor properties
    actor_weapon.id = NPC;
    actor_weapon.name = NULL;
    actor_weapon.block_x = 0;
    actor_weapon.block_y = 0;
    actor_weapon.display_x = 0;
    actor_weapon.display_y = 0;

    // display
    actor_weapon.color = 0xFFFF;
    ImageSlice weapon_slice;
    ImageSlice_new(&weapon_slice);
    weapon_slice.img = gun_img;
    weapon_slice.w = gun_img.w;
    weapon_slice.h = gun_img.h;
    actor_weapon.image = weapon_slice;

    // functions
    actor_weapon.start = weapon_start;
    actor_weapon.process = weapon_process;
    actor_weapon.custom_draw = NULL;
}

#endif // WEAPON_H
