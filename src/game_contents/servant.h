#if !defined(SERVANT_H)
#define SERVANT_H

#include "../globals.h"
#include "../game_server/actor.h"
#include "../images/image_slice.h"
#include "tilesets.h"


Actor actor_servant;

void servant_start(Actor *self)
{
    // nothing
}

void servant_process(Actor *self)
{
    // check player position and start conversation?
    // nothing currently
}


void init_servant()
{
    Actor_new(&actor_servant);
    // actor properties
    actor_servant.id = NPC;
    actor_servant.name = NULL;
    actor_servant.block_x = 0;
    actor_servant.block_y = 0;
    actor_servant.display_x = 0;
    actor_servant.display_y = 0;

    // display
    actor_servant.color = 0xFFFF;
    actor_servant.image = Tileset_get_tile(&character_set, 160);
    actor_servant.image.origin_x = 8;
    actor_servant.image.origin_y = 16;

    // functions
    actor_servant.start = servant_start;
    actor_servant.process = servant_process;
    actor_servant.custom_draw = NULL;
}

#endif // SERVANT_H
