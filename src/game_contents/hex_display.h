#if !defined(HEX_DISPLAY_H)
#define HEX_DISPLAY_H

#include <stdlib.h>

#include "../globals.h"
#include "../game_server/actor.h"
#include "../images/image_slice.h"
#include "../images/short_image.h"
#include "tilesets.h"


typedef struct
{
    Actor base;
    int value;
} ActorHEXDisplay;

ActorHEXDisplay actor_hex0;
ActorHEXDisplay actor_hex1;
ActorHEXDisplay actor_hex2;
ActorHEXDisplay actor_hex3;
ActorHEXDisplay actor_hex4;
ActorHEXDisplay actor_hex5;

void hex_set_value(ActorHEXDisplay* self, int val){
    val %= 16;
    self->value = val;
    ImageSlice slice;
    ImageSlice_new(&slice);
    slice.img = hex_set_img;
    slice.x = val * 16;
    slice.y = 0;
    slice.w = 16;
    slice.h = 32;
    slice.origin_x = 0;
    slice.origin_y = 16;
    self->base.image = slice;
}

void init_hex()
{
    Actor_new((Actor*)&actor_hex0);
    Actor_new((Actor*)&actor_hex1);
    Actor_new((Actor*)&actor_hex2);
    Actor_new((Actor*)&actor_hex3);
    Actor_new((Actor*)&actor_hex4);
    Actor_new((Actor*)&actor_hex5);
    hex_set_value(&actor_hex0, rand() & 0xFF);
    hex_set_value(&actor_hex1, rand() & 0xFF);
    hex_set_value(&actor_hex2, rand() & 0xFF);
    hex_set_value(&actor_hex3, rand() & 0xFF);
    hex_set_value(&actor_hex4, rand() & 0xFF);
    hex_set_value(&actor_hex5, rand() & 0xFF);
    actor_hex0.base.id = NPC;
    actor_hex1.base.id = NPC;
    actor_hex2.base.id = NPC;
    actor_hex3.base.id = NPC;
    actor_hex4.base.id = NPC;
    actor_hex5.base.id = NPC;
}

#endif // HEX_DISPLAY_H
