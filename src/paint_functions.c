#include <stdlib.h>
#include <stdio.h>

#include "const.h"
#include "paint_functions.h"
#include "screen_server/screen_server.h"
#include "utils.h"
#include "font5x7.h"

void fill(ScreenServer *server, short color)
{
    int x, y;
    for (x = 0; x < RESOLUTION_X; x++)
    {
        for (y = 0; y < RESOLUTION_Y; y++)
        {
            server->draw_pixel(server, x, y, color);
        }
    }
}

void draw_line(ScreenServer *server, int x1, int y1, int x2, int y2, short color)
{
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    int y_first;
    if (dx >= dy)
    {
        y_first = 0;
    }
    else
    {
        y_first = 1;
        // swap x and y
        int temp;
        temp = x1;
        x1 = y1;
        y1 = temp;
        temp = x2;
        x2 = y2;
        y2 = temp;
    }

    // sort
    if (x1 > x2)
    {
        int temp;
        temp = x1; // swap x
        x1 = x2;
        x2 = temp;
        temp = y1; // swap y
        y1 = y2;
        y2 = temp;
    }
    // update dx dy
    dx = x2 - x1;
    dy = abs(y2 - y1);

    // set increament y
    int inc_y = 1;
    if (y1 > y2)
    {
        inc_y = -1;
    }

    int unit_lenth = dx;
    int error_y = unit_lenth / 2;
    int y = y1;

    for (int i = 0; i < dx; i += 1)
    {
        int x = x1 + i;

        if (y_first)
        {
            server->draw_pixel(server, y, x, color);
        }
        else
        {
            server->draw_pixel(server, x, y, color);
        }

        error_y -= dy;
        if (error_y <= 0)
        {
            y += inc_y;
            error_y += unit_lenth;
        }
    }
}

void draw_rect(ScreenServer *server, int x, int y, int w, int h, short color)
{
    if (w <= 0 || h <= 0)
        return;
    int dx, dy;
    for (dx = 0; dx < w; dx++)
    {
        for (dy = 0; dy < h; dy++)
        {
            server->draw_pixel(server, x + dx, y + dy, color);
        }
    }
}

void draw_img(ScreenServer *server, int x, int y, ShortImage img)
{
    int dx, dy;
    unsigned int offset;
    if (img.mask == NULL) // no alpha channel
    {
        for (dy = 0; dy < img.h; dy++)
        {
            for (dx = 0; dx < img.w; dx++)
            {
                offset = dy * img.w + dx;
                server->draw_pixel(server, x + dx, y + dy, img.data[offset]);
            }
        }
    }
    else
    { // has alpha
        for (dy = 0; dy < img.h; dy++)
        {
            for (dx = 0; dx < img.w; dx++)
            {
                unsigned int offset = dy * img.w + dx;

                unsigned int mask_byte_offset = offset / 8;       // the byte position
                unsigned char mask_bit_offset = 7 - (offset % 8); // the bit position, is inverted
                unsigned char mask = (img.mask[mask_byte_offset] & (1 << mask_bit_offset)) >> mask_bit_offset;
                if (mask)
                {
                    server->draw_pixel(server, x + dx, y + dy, img.data[offset]);
                }
            }
        }
    }
}

void draw_img_slice(ScreenServer *server, int x, int y, ImageSlice slice)
{
    slice.x = max(0, min(slice.x, slice.img.w));
    slice.y = max(0, min(slice.y, slice.img.h));
    slice.w = max(0, min(slice.w, slice.img.w - slice.x));
    slice.h = max(0, min(slice.h, slice.img.h - slice.y));

    // origin shift
    x -= slice.origin_x;
    y -= slice.origin_y;

    int dx, dy;
    unsigned int offset;
    if (slice.img.mask == NULL) // no alpha channel
    {
        for (dy = 0; dy < slice.h; dy++)
        {
            for (dx = 0; dx < slice.w; dx++)
            {
                offset = (slice.y + dy) * slice.img.w + (slice.x + dx);
                // handel xy flipping
                int screen_x, screen_y;
                if (slice.flip_x)
                    screen_x = x + slice.w - dx;
                else
                    screen_x = x + dx;
                if (slice.flip_y)
                    screen_y = y + slice.h - dy;
                else
                    screen_y = y + dy;

                server->draw_pixel(server, screen_x, screen_y, slice.img.data[offset]);
            }
        }
    }
    else
    { // has alpha
        unsigned int offset;
        unsigned int mask_byte_offset;
        unsigned char mask_bit_offset;
        unsigned char mask;

        for (dy = 0; dy < slice.h; dy++)
        {
            for (dx = 0; dx < slice.w; dx++)
            {
                offset = (slice.y + dy) * slice.img.w + (slice.x + dx);

                mask_byte_offset = offset / 8;      // the byte position
                mask_bit_offset = 7 - (offset % 8); // the bit position, is inverted
                mask = (slice.img.mask[mask_byte_offset] & (1 << mask_bit_offset)) >> mask_bit_offset;
                if (mask)
                {
                    // handel xy flipping
                    int screen_x, screen_y;
                    if (slice.flip_x)
                        screen_x = x + slice.w - dx;
                    else
                        screen_x = x + dx;
                    if (slice.flip_y)
                        screen_y = y + slice.h - dy;
                    else
                        screen_y = y + dy;

                    server->draw_pixel(server, screen_x, screen_y, slice.img.data[offset]);
                }
            }
        }
    }
}

void draw_img_color(ScreenServer *server, int x, int y, ShortImage img, short color)
{
    int dx, dy;
    unsigned int offset;
    unsigned char r1, g1, b1;
    unsigned char r2, g2, b2;
    short new_color;

    if (img.mask == NULL) // no alpha channel
    {
        for (dy = 0; dy < img.h; dy++)
        {
            for (dx = 0; dx < img.w; dx++)
            {
                offset = dy * img.w + dx;

                short2rgb(img.data[offset], &r1, &g1, &b1);
                short2rgb(color, &r2, &g2, &b2);
                new_color = rgb2short(r1 * r2 / 255, g1 * g2 / 255, b1 * b2 / 255);

                server->draw_pixel(server, x + dx, y + dy, new_color);
            }
        }
    }
    else
    { // has alpha
        for (dy = 0; dy < img.h; dy++)
        {
            for (dx = 0; dx < img.w; dx++)
            {
                unsigned int offset = dy * img.w + dx;

                unsigned int mask_byte_offset = offset / 8;       // the byte position
                unsigned char mask_bit_offset = 7 - (offset % 8); // the bit position, is inverted
                unsigned char mask = (img.mask[mask_byte_offset] & (1 << mask_bit_offset)) >> mask_bit_offset;
                if (mask)
                {
                    short2rgb(img.data[offset], &r1, &g1, &b1);
                    short2rgb(color, &r2, &g2, &b2);
                    new_color = rgb2short(r1 * r2 / 255, g1 * g2 / 255, b1 * b2 / 255);

                    server->draw_pixel(server, x + dx, y + dy, new_color);
                }
            }
        }
    }
}

void draw_img_slice_color(ScreenServer *server, int x, int y, ImageSlice slice, short color)
{
    slice.x = max(0, min(slice.x, slice.img.w));
    slice.y = max(0, min(slice.y, slice.img.h));
    slice.w = max(0, min(slice.w, slice.img.w - slice.x));
    slice.h = max(0, min(slice.h, slice.img.h - slice.y));

    int dx, dy;
    unsigned int offset;

    unsigned char r1, g1, b1;
    unsigned char r2, g2, b2;
    short new_color;

    // origin shift
    x -= slice.origin_x;
    y -= slice.origin_y;

    if (slice.img.mask == NULL) // no alpha channel
    {
        for (dy = 0; dy < slice.h; dy++)
        {
            for (dx = 0; dx < slice.w; dx++)
            {
                offset = (slice.y + dy) * slice.img.w + (slice.x + dx);

                short2rgb(slice.img.data[offset], &r1, &g1, &b1);
                short2rgb(color, &r2, &g2, &b2);
                new_color = rgb2short(r1 * r2 / 255, g1 * g2 / 255, b1 * b2 / 255);

                // handel xy flipping
                int screen_x, screen_y;
                if (slice.flip_x)
                    screen_x = x + slice.w - dx;
                else
                    screen_x = x + dx;
                if (slice.flip_y)
                    screen_y = y + slice.h - dy;
                else
                    screen_y = y + dy;

                server->draw_pixel(server, screen_x, screen_y, new_color);
            }
        }
    }
    else
    { // has alpha
        unsigned int offset;
        unsigned int mask_byte_offset;
        unsigned char mask_bit_offset;
        unsigned char mask;

        for (dy = 0; dy < slice.h; dy++)
        {
            for (dx = 0; dx < slice.w; dx++)
            {
                offset = (slice.y + dy) * slice.img.w + (slice.x + dx);

                mask_byte_offset = offset / 8;      // the byte position
                mask_bit_offset = 7 - (offset % 8); // the bit position, is inverted
                mask = (slice.img.mask[mask_byte_offset] & (1 << mask_bit_offset)) >> mask_bit_offset;
                if (mask)
                {
                    short2rgb(slice.img.data[offset], &r1, &g1, &b1);
                    short2rgb(color, &r2, &g2, &b2);
                    new_color = rgb2short(r1 * r2 / 255, g1 * g2 / 255, b1 * b2 / 255);

                    // handel xy flipping
                    int screen_x, screen_y;
                    if(slice.flip_x)
                        screen_x = x + slice.w - dx;
                    else
                        screen_x = x + dx;
                    if(slice.flip_y)
                        screen_y = y + slice.h - dy;
                    else
                        screen_y = y + dy;

                    server->draw_pixel(server, screen_x, screen_y, new_color);
                }
            }
        }
    }
}

void draw_char(ScreenServer *server, int x, int y, char c, short color)
{
    int font_data_offset = c * FONT_W;
    int row, col;
    for (row = 0; row < FONT_H; row++)
    {
        for (col = 0; col < FONT_W; col++)
        {
            int screen_x, screen_y;
            screen_x = x + col;
            screen_y = y + FONT_H - row;
            int byte = font5x7[font_data_offset + col];
            int bit_offset = 7 - row;
            int bit = (byte & (1 << bit_offset)) >> bit_offset;
            if (bit)
            {
                server->draw_pixel(server, screen_x, screen_y, color);
            }
        }
    }
}
