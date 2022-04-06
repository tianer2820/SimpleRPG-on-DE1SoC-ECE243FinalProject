#include <stdlib.h>
#include <stdio.h>

#include "../const.h"
#include "screen_server.h"


ScreenServer* ScreenServer_new(ScreenServer* self){
    if (self != NULL)
    {
        return self;
    }
    return calloc(1, sizeof(ScreenServer));
}

void ScreenServer_delete(ScreenServer* self){
    free(self);
}
