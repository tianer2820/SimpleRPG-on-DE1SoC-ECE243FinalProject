#include <stdlib.h>
#include <stdio.h>

#include "../const.h"
#include "../utils.h"
#include "screen_server.h"

ScreenServer *ScreenServer_new(ScreenServer *self)
{
    if (self != NULL)
    {
        self->dirty_region.x = 0;
        self->dirty_region.y = 0;
        self->dirty_region.w = 0;
        self->dirty_region.h = 0;
        return self;
    }
    return calloc(1, sizeof(ScreenServer));
}

void ScreenServer_delete(ScreenServer *self)
{
    free(self);
}

void ScreenServer_dirty_region(ScreenServer *self, Rect2D region)
{
    if (self->dirty_region.w == 0 || self->dirty_region.h == 0)
    {
        self->dirty_region = region;
        return;
    }
    
    int top = min(self->dirty_region.y, region.y);
    int buttom = max(self->dirty_region.y + self->dirty_region.y,
                     region.y + region.h);
    int left = min(self->dirty_region.x, region.x);
    int right = max(self->dirty_region.x + self->dirty_region.w,
                    region.x + region.w);

    self->dirty_region.x = left;
    self->dirty_region.y = top;
    self->dirty_region.w = right - left;
    self->dirty_region.h = buttom - top;
}

void ScreenServer_dirty_clear(ScreenServer *self){
    self->dirty_region.x = 0;
    self->dirty_region.y = 0;
    self->dirty_region.w = 0;
    self->dirty_region.h = 0;
}

void ScreenServer_dirty_all(ScreenServer* self){
    self->dirty_region.x = 0;
    self->dirty_region.y = 0;
    self->dirty_region.w = RESOLUTION_X;
    self->dirty_region.h = RESOLUTION_Y;

    self->dirty_region_back.x = 0;
    self->dirty_region_back.y = 0;
    self->dirty_region_back.w = RESOLUTION_X;
    self->dirty_region_back.h = RESOLUTION_Y;
}