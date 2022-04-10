#if !defined(INTERACT_POINT_H)
#define INTERACT_POINT_H

#include <stdlib.h>

typedef struct InteractPointStruct
{
    const char* action_name_str;
    void (*interact)(struct InteractPointStruct* self);
    int x;
    int y;
} InteractPoint;


InteractPoint* InteractPoint_new(InteractPoint* self){
    InteractPoint* point = self;
    if (point == NULL)
    {
        point = (InteractPoint*)calloc(1, sizeof(InteractPoint));
    }
    point->action_name_str = NULL;
    point->interact = NULL;
    point->x = 0;
    point->y = 0;
    return point;
}


#endif // INTERACT_POINT_H
