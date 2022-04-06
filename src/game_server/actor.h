#if !defined(ACTOR_H)
#define ACTOR_H


#include "../images/image_slice.h"


enum ACTOR_ID{
    NONE,
    PLAYER,
    NPC_TEST,
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
} Actor;


/* allocate memory (if needed) and clear all fields of the actor object */
Actor* Actor_new(Actor* self){
    Actor* actor = self;
    if (actor == NULL)
    {
        actor = calloc(1, sizeof(Actor));
    }
    actor->id = NONE;
    actor->name = NULL;
    actor->block_x = 0;
    actor->block_y = 0;
    actor->display_x = 0;
    actor->display_y = 0;
    ImageSlice_new(&(actor->image));
    actor->image;
    actor->color = 0xFFFF;
    actor->start = NULL;
    actor->process = NULL;
    actor->custom_draw = NULL;
    return actor;
}


#endif // ACTOR_H
