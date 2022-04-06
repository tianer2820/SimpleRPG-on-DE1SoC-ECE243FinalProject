/**
 * The basic backend interface for a screen.
 */

#if !defined(SCREEN_SERVER_H)
#define SCREEN_SERVER_H


#include <stdlib.h>
#include <stdio.h>

#include "../const.h"


typedef struct ScreenServerStruct
{
    // init & stop
    void (*init)(struct ScreenServerStruct* self);
    void (*stop)(struct ScreenServerStruct* self);

    // plot functions
    void (*draw_pixel)(struct ScreenServerStruct* self, int x, int y, short color);

    // flip
    void (*flip)(struct ScreenServerStruct* self);

} ScreenServer;


ScreenServer* ScreenServer_new(ScreenServer* self);
void ScreenServer_delete(ScreenServer* self);


#endif // SCREEN_SERVER_H

