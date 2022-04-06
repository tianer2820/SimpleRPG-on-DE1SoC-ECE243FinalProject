#if !defined(ANIME_PLAYER_H)
#define ANIME_PLAYER_H

#include "../const.h"

typedef struct
{
    // public
    float value;
    int total_frame;
    int current_frame;
    bool is_done;
    // private
    float _initial_val;
    float _delta_val;
} AnimePlayer;

void AnimePlayer_reset(AnimePlayer *self)
{
    self->_initial_val = 0;
    self->_delta_val = 0;
    self->value = 0;

    self->total_frame = 0;
    self->current_frame = 0;
    self->is_done = true;
}

void AnimePlayer_start(AnimePlayer *self, float from, float to, int frames)
{
    self->_initial_val = from;
    self->_delta_val = to - from;

    self->total_frame = frames;
    self->current_frame = 0;
    if (frames > 0)
    {
        self->value = from;
        self->is_done = false;
    }
    else
    {
        self->value = to;
        self->is_done = true;
    }
}

float AnimePlayer_next_frame(AnimePlayer *self)
{
    if (self->is_done)
        return self->value;
    // calc value
    self->current_frame += 1;
    self->value = self->_initial_val + (self->_delta_val * self->current_frame / self->total_frame);
    // check is done
    if (self->current_frame >= self->total_frame)
        self->is_done = true;

    return self->value;
}

#endif // ANIME_PLAYER_H
