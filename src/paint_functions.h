
#if !defined(PAINT_FUNCTIONS_H)
#define PAINT_FUNCTIONS_H


#include <stdlib.h>

#include "const.h"
#include "screen_server/screen_server.h"
#include "images/short_image.h"
#include "images/image_slice.h"


void fill(ScreenServer *server, short color);
void draw_line(ScreenServer *server, int x1, int y1, int x2, int y2, short color);
void draw_rect(ScreenServer *server, int x, int y, int w, int h, short color);
void draw_img(ScreenServer *server, int x, int y, ShortImage img);
void draw_img_slice(ScreenServer *server, int x, int y, ImageSlice slice);

void draw_img_color(ScreenServer *server, int x, int y, ShortImage img, short color);
void draw_img_slice_color(ScreenServer *server, int x, int y, ImageSlice slice, short color);

void draw_char(ScreenServer *server, int x, int y, char c, short color);

#endif // PAINT_FUNCTIONS_H



