#if !defined(ACTOR_H)
#define ACTOR_H


#include "../images/image_slice.h"


enum ACTOR_ID{
    NONE,
    PLAYER,
    NPC,
};

typedef struct ActorStruct
{
    enum ACTOR_ID id;
    char* name;
    ImageSlice image;
    short color;
    int block_x;
    int block_y;
    float display_x;
    float display_y;

    void (*start)(struct ActorStruct* self);
    void (*process)(struct ActorStruct* self);
    void (*custom_draw)(struct ActorStruct* self);
    void (*set_position)(struct ActorStruct* self, int x, int y);
} Actor;


void Actor_set_position(struct ActorStruct* self, int x, int y){
    self->block_x = x;
    self->block_y = y;
    self->display_x = x;
    self->display_y = y;
}

/* allocate memory (if needed) and clear all fields of the actor object */
Actor* Actor_new(Actor* self){
    Actor* actor = self;
    if (actor == NULL)
    {
        actor = (Actor*)calloc(1, sizeof(Actor));
    }
    actor->id = NONE;
    actor->name = NULL;
    actor->block_x = 0;
    actor->block_y = 0;
    actor->display_x = 0;
    actor->display_y = 0;
    ImageSlice_new(&(actor->image));
    actor->color = 0xFFFF;
    actor->start = NULL;
    actor->process = NULL;
    actor->custom_draw = NULL;
    actor->set_position = Actor_set_position;
    return actor;
}


#endif // ACTOR_H
