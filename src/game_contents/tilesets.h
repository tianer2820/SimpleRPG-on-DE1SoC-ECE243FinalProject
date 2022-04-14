#if !defined(TILESETS_H)
#define TILESETS_H


#include "../images/short_image.h"
#include "../images/image_slice.h"
#include "../tilemap/tileset.h"
#include "resources.h"

ShortImage simple_set_img;
Tileset simple_set;
const unsigned char simple_set_solid[] = {
0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x1, 
0xfd, 0x0, 0x40, 0x5, 0xe5, 0xe1, 0x0, 0x0,
0x2, 0xe2, 0xe0, 0x10, 0x10, 0x0, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x23, 0x3, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
0x3, 0x0, 0x3, 0x3, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
0x3f, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xc7, 0xff,
0xff, 0x7, 0x7, 0x7, 0x7, 0x5f, 0xff, 0xe7,
0x0, 0x18, 0xf8, 0x0, 0x0, 0x0, 0xfe, 0xfe,
0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0xfc, 0xfc, 0xf0, 0xf0,
};


ShortImage character_set_img;
Tileset character_set;

ShortImage hex_set_img;

void init_tilesets(){
    // init image
    simple_set_img.w = RES_ALL_TILES_W;
    simple_set_img.h = RES_ALL_TILES_H;
    simple_set_img.data = RES_ALL_TILES_DATA;
    simple_set_img.mask = RES_ALL_TILES_MASK;

    character_set_img.w = RES_CHARACTERS_W;
    character_set_img.h = RES_CHARACTERS_H;
    character_set_img.data = RES_CHARACTERS_DATA;
    character_set_img.mask = RES_CHARACTERS_MASK;

    hex_set_img.w = RES_HEX_DISPLAY_W;
    hex_set_img.h = RES_HEX_DISPLAY_H;
    hex_set_img.data = RES_HEX_DISPLAY_DATA;
    hex_set_img.mask = RES_HEX_DISPLAY_MASK;


    // init tileset
    simple_set.img = simple_set_img;
    simple_set.w = RES_ALL_TILES_W / 16;
    simple_set.h = RES_ALL_TILES_H / 16;
    simple_set.tile_size = 16;
    simple_set.solid_mask = simple_set_solid;

    character_set.img = character_set_img;
    character_set.w = RES_CHARACTERS_W / 32;
    character_set.h = RES_CHARACTERS_H / 32;
    character_set.tile_size = 32;
    character_set.solid_mask = NULL;

}

#endif // TILESETS_H
