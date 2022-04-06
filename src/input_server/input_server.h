#if !defined(INPUT_SERVER_H)
#define INPUT_SERVER_H

#include <stdlib.h>
#include "../const.h"
#include "scan_code.h"


typedef struct InputServerStruct
{
    void (*init)(struct InputServerStruct* self);
    void (*update)(struct InputServerStruct* self);
    void (*stop)(struct InputServerStruct* self);
    bool (*key_is_pressed)(struct InputServerStruct* self, KeyScancode key);
} InputServer;


InputServer* InputServer_new(InputServer* self){
    InputServer* server = self;
    if (server == NULL)
    {
        server = (InputServer*)calloc(1, sizeof(InputServer));
    }
    server->init = NULL;
    server->key_is_pressed = NULL;
    server->update = NULL;
    server->stop = NULL;
    return server;
}


#endif // INPUT_SERVER_H
