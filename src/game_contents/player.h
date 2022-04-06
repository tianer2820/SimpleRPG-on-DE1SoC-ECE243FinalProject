#if !defined(PLAYER_H)
#define PLAYER_H

#include "../globals.h"
#include "../game_server/actor.h"
#include "../anime/anime_player.h"
#include "../images/image_slice.h"
#include "tilesets.h"

#define PLAYER_MOVE_FRAMES 10
#define PLAYER_ANIME_FRAMES 4

typedef struct ActorPlayerStruct
{
    Actor base;

    AnimePlayer anime_x;
    AnimePlayer anime_y;
    int anime_frame;
    ImageSlice anime_slices[4];
    bool flip_x;
} ActorPlayer;

ActorPlayer actor_player;

void player_start(ActorPlayer *self)
{
    // setup animation
    AnimePlayer_start(&self->anime_x, self->base.block_x, self->base.block_x, 0);
    AnimePlayer_start(&self->anime_y, self->base.block_y, self->base.block_y, 0);
}

void player_process(ActorPlayer *self)
{
    short dx = 0;
    short dy = 0;
    if (self->anime_x.is_done) // only move if last anime is done
    {
        // get move direction vec
        if (input_server->key_is_pressed(input_server, K_SCANCODE_A))
            dx -= 1;
        if (input_server->key_is_pressed(input_server, K_SCANCODE_D))
            dx += 1;
        if (dx == 0) // prevent diagonal move
        {
            if (input_server->key_is_pressed(input_server, K_SCANCODE_W))
                dy -= 1;
            if (input_server->key_is_pressed(input_server, K_SCANCODE_S))
                dy += 1;
        }

        if (dx != 0 || dy != 0) // is moving
        {
            // check obsticles
            int next_x = self->base.block_x + dx;
            int next_y = self->base.block_y + dy;
            if (Scene_tile_is_solid(game_server->scene, next_x, next_y))
            {
                // refuse moving into the wall
            }
            else
            {
                // setup animation
                AnimePlayer_start(&self->anime_x, self->base.block_x, next_x, PLAYER_MOVE_FRAMES);
                AnimePlayer_start(&self->anime_y, self->base.block_y, next_y, PLAYER_MOVE_FRAMES);
                self->base.block_x = next_x;
                self->base.block_y = next_y;
            }

            // if inside solid, render player red
            if (Scene_tile_is_solid(game_server->scene, self->base.block_x, self->base.block_y))
                self->base.color = RED;
            else
                self->base.color = WHITE;

            // flip player
            if (dx > 0)
                self->flip_x = false;
            else if (dx < 0)
                self->flip_x = true;
        }
    }
    // update position animation
    AnimePlayer_next_frame(&(self->anime_x));
    AnimePlayer_next_frame(&(self->anime_y));
    self->base.display_x = self->anime_x.value;
    self->base.display_y = self->anime_y.value;

    // update image animation
    if ((!self->anime_x.is_done) || (!self->anime_y.is_done))
    { // is running
        self->base.image = self->anime_slices[self->anime_frame / PLAYER_ANIME_FRAMES];
        self->anime_frame = (self->anime_frame + 1) % (4 * PLAYER_ANIME_FRAMES);
    }
    else // idle
        self->base.image = self->anime_slices[0];
    self->base.image.flip_x = self->flip_x;
}

void init_player()
{
    Actor_new(&actor_player);
    // actor properties
    Actor *actor = &actor_player;
    actor->id = PLAYER;
    actor->name = NULL;
    actor->block_x = 0;
    actor->block_y = 0;
    actor->display_x = 0;
    actor->display_y = 0;

    // display
    actor_player.anime_frame = 0;
    int i;
    for (i = 0; i < 4; i++)
    {
        actor_player.anime_slices[i] = Tileset_get_tile(&character_set, 4+i);
        actor_player.anime_slices[i].origin_x = 8;
        actor_player.anime_slices[i].origin_y = 16;
    }
    actor->color = 0xFFFF;
    // player properties
    AnimePlayer_reset(&(actor_player.anime_x));
    AnimePlayer_reset(&(actor_player.anime_y));

    // functions
    actor->start = player_start;
    actor->process = player_process;
    actor->custom_draw = NULL;
}

#endif // PLAYER_H
