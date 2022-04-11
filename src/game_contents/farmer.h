#if !defined(FARMER_H)
#define FARMER_H

#include "../globals.h"
#include "../game_server/actor.h"
#include "../anime/anime_player.h"
#include "../images/image_slice.h"
#include "tilesets.h"


Actor actor_farmer;

void farmer_start(Actor *self)
{
    // nothing
}

void farmer_process(Actor *self)
{
    // check player position and start conversation?
    // nothing currently
}


void init_farmer()
{
    Actor_new(&actor_farmer);
    // actor properties
    actor_farmer.id = NPC;
    actor_farmer.name = NULL;
    actor_farmer.block_x = 0;
    actor_farmer.block_y = 0;
    actor_farmer.display_x = 0;
    actor_farmer.display_y = 0;

    // display
    actor_farmer.color = 0xFFFF;
    actor_farmer.image = Tileset_get_tile(&character_set, 28);
    actor_farmer.image.origin_x = 8;
    actor_farmer.image.origin_y = 16;

    // functions
    actor_farmer.start = farmer_start;
    actor_farmer.process = farmer_process;
    actor_farmer.custom_draw = NULL;
}

#endif // FARMER_H
