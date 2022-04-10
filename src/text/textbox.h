#if !defined(TEXTBOX_H)
#define TEXTBOX_H

#include "../const.h"
#include "../utils.h"
#include "../screen_server/screen_server.h"
#include "../paint_functions.h"
#include "../font5x7.h"

/* return the size of textbox in pixels */
void estimate_textbox_size(char* text, int* w, int* h){
    int text_w = 0;
    int text_h = 1;
    int line_len = 0;
    int i = 0;
    while (true)
    {
        char c = text[i];
        if (c == '\0')
            break; // end of string
        else if (c == '\n') // new line
        {
            text_h += 1;
            text_w = max(text_w, line_len);
            line_len = 0;
        }
        else
            line_len += 1; // normal text
        i += 1;
    }
    text_w = max(text_w, line_len); // include last line

    // box size on screen
    *w = text_w * (FONT_W + 1);
    *h = text_h * (FONT_H + 1);
}

/*  */
void draw_textbox(ScreenServer *server, char *text, int x, int y, short color,
                  bool use_bg, short bg_color, bool use_border, short border_color)
{
    // estimate box size on screen
    int size_w, size_h;
    estimate_textbox_size(text, &size_w, &size_h);

    // draw background if needed
    if (use_bg)
        draw_rect(server, x-1, y-1, size_w+1, size_h+1, bg_color);
    // draw border if needed
    // TODO

    // draw text
    int i = 0;
    int cursor_x = 0;
    int cursor_y = 0;
    while (true)
    {
        char c = text[i];
        if (c == '\0')
            break; // end of string
        else if (c == '\n') // new line
        {
            cursor_y += FONT_H + 1;
            cursor_x = 0;
        }
        else{
            // normal text
            draw_char(server, x + cursor_x, y + cursor_y, c, color);
            cursor_x += FONT_W + 1;
        }
        i += 1;
    }
    
}

#endif // TEXTBOX_H
