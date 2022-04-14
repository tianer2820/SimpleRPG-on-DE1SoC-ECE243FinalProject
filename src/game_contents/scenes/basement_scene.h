#if !defined(BASEMENT_SCENE_H)
#define BASEMENT_SCENE_H

#include <stdlib.h>
#include "../../globals.h"
#include "scenes_globals.h"

#include "../../images/short_image.h"
#include "../../tilemap/tilemap.h"
#include "../../tilemap/tileset.h"
#include "../../game_server/scene.h"
#include "../../game_server/interact_point.h"

#include "../resources.h"
#include "../tilesets.h"
#include "../player.h"
#include "../hex_display.h"
#include "../weapon.h"

const int mapdata_basement_layer1[] = {
467,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,467,
467,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,467,
467,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,467,
467,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,465,467,
475,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,473,475,

};
const int mapdata_basement_layer2[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,923,924,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,931,932,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,618,-1,-1,-1,618,-1,-1,-1,487,487,-1,-1,618,-1,-1,-1,
-1,-1,939,940,-1,-1,-1,-1,-1,-1,-1,-1,495,495,-1,-1,-1,-1,-1,-1,
-1,-1,947,948,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,876,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,859,-1,
-1,343,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,859,-1,859,-1,-1,
-1,351,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,869,951,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,859,-1,868,951,-1,869,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

Tilemap tilemap_basement_layer1;
Tilemap tilemap_basement_layer2;


Dialog dialog_password;
char *dialog_password_text = "\
Engineers save the world!\n\
\n\
1110 1100 1110\n\
0010 0100 0011";
char *dialog_password_choice1 = "F: Ok..";


InteractPoint point_password;
const char* point_password_label = "Read";
void point_password_interact(InteractPoint* self){
    GameServer_set_dialog(game_server, &dialog_password);
}

InteractPoint points_inc_hex[6];
const char* points_inc_hex_label = "Add one";
void points_inc_hex_interact(InteractPoint* self){
    int number = (actor_player.base.block_x - 5);
    ActorHEXDisplay* hex = get_hex_display(number);
    hex_set_value(hex, hex->value + 1);
}

InteractPoint point_tp_in;
const char* point_tp_in_label = "Enter";
void point_tp_in_interact(InteractPoint* self){
    int password[] = {0xE, 0xC, 0xE, 0x2, 0x4, 0x3};
    int i;
    bool wrong = false;
    for (i = 0; i < 6; i++)
    {
        ActorHEXDisplay* hex = get_hex_display(i);
        if(hex->value != password[i]){
            // wrong, set dialog maybe
            wrong = true;
            break;
        }
    }
    if(!wrong){
        // tp player
        GameServer_move_player(game_server, 12, 4);
    }
}


InteractPoint point_tp_out;
const char* point_tp_out_label = "Exit";
void point_tp_out_interact(InteractPoint* self){
    GameServer_move_player(game_server, 12, 7);
}


InteractPoint point_weapon;
const char* point_weapon_label = "Pick up";
void point_weapon_interact(InteractPoint* self){
    ImageSlice_new(&(actor_weapon.image));
    weapon_pickedup = true;
}


InteractPoint point_back_ruin;
const char* point_back_ruin_label = "Leave";
void point_back_ruin_interact(InteractPoint* self){
    GameServer_load_scene(game_server, &scene_ruins);
    GameServer_move_player(game_server, 6, 7);
}


void scene_basement_setup(Scene *self)
{
    // setup player
    game_server->actor_list[6] = (Actor*)&actor_player;
    game_server->player = (Actor*)&actor_player;
    GameServer_move_player(game_server, 2, 10);

    int i;
    for (i = 0; i < 6; i++)
    {
        game_server->actor_list[i] = (Actor*)get_hex_display(i);
    }
    
    game_server->actor_list[7] = (Actor*)&actor_weapon;
    actor_weapon.block_x = 9;
    actor_weapon.block_y = 3;
    actor_weapon.display_x = 9;
    actor_weapon.display_y = 3;

    // setup interact points
    for (i = 0; i < 6; i++)
    {
        game_server->interact_points[i] = points_inc_hex + i;
    }
    
    game_server->interact_points[6] = &point_password;
    game_server->interact_points[7] = &point_tp_in;
    game_server->interact_points[8] = &point_tp_out;
    game_server->interact_points[9] = &point_weapon;
    game_server->interact_points[10] = &point_back_ruin;
}


void init_scene_basement()
{
    // tilemap layers
    tilemap_basement_layer1.tileset = &simple_set;
    tilemap_basement_layer1.map_data = mapdata_basement_layer1;
    tilemap_basement_layer1.w = 20;
    tilemap_basement_layer1.h = 14;

    tilemap_basement_layer2.tileset = &simple_set;
    tilemap_basement_layer2.map_data = mapdata_basement_layer2;
    tilemap_basement_layer2.w = 20;
    tilemap_basement_layer2.h = 14;

    // scene
    Scene_new(&scene_basement); // clear init memory
    scene_basement.map_layers[0] = &tilemap_basement_layer1;
    scene_basement.map_layers[1] = &tilemap_basement_layer2;
    scene_basement.ambient_color = WHITE;
    scene_basement.setup = scene_basement_setup;

    // hex display
    int i;
    for (i = 0; i < 6; i++)
    {
        ActorHEXDisplay* hex = get_hex_display(i);
        hex->base.block_x = i + 5;
        hex->base.display_x = i + 5;
        hex->base.block_y = 6;
        hex->base.display_y = 6;
    }

    // interact points
    for (i = 0; i < 6; i++)
    {
        points_inc_hex[i].action_name_str = points_inc_hex_label;
        points_inc_hex[i].interact = points_inc_hex_interact;
        points_inc_hex[i].x = i + 5;
        points_inc_hex[i].y = 7;
    }
    point_password.action_name_str = point_password_label;
    point_password.interact = point_password_interact;
    point_password.x = 3;
    point_password.y = 8;

    point_tp_in.action_name_str = point_tp_in_label;
    point_tp_in.interact = point_tp_in_interact;
    point_tp_in.x = 12;
    point_tp_in.y = 7;

    point_tp_out.action_name_str = point_tp_out_label;
    point_tp_out.interact = point_tp_out_interact;
    point_tp_out.x = 12;
    point_tp_out.y = 4;

    point_weapon.action_name_str = point_weapon_label;
    point_weapon.interact = point_weapon_interact;
    point_weapon.x = 10;
    point_weapon.y = 4;

    point_back_ruin.action_name_str = point_back_ruin_label;
    point_back_ruin.interact = point_back_ruin_interact;
    point_back_ruin.x = 2;
    point_back_ruin.y = 10;


    // point_bulleitin_board.action_name_str = point_bulleitin_board_label;
    // point_bulleitin_board.interact = point_bulleitin_board_interact;
    // point_bulleitin_board.x = 13;
    // point_bulleitin_board.y = 9;

    // dialog
    Dialog_new(&dialog_password);
    dialog_password.text = dialog_password_text;
    dialog_password.choice1 = dialog_password_choice1;

    // Dialog_new(&dialog_servant_1);
    // dialog_servant_1.text = dialog_servant_1_text;
    // dialog_servant_1.choice1 = dialog_servant_1_choice1;
    // dialog_servant_1.next1 = &dialog_servant_2;
    // Dialog_new(&dialog_servant_2);
    // dialog_servant_2.text = dialog_servant_2_text;
    // dialog_servant_2.choice1 = dialog_servant_2_choice1;
    // dialog_servant_2.next1 = &dialog_servant_3;
    // Dialog_new(&dialog_servant_3);
    // dialog_servant_3.text = dialog_servant_3_text;
    // dialog_servant_3.choice1 = dialog_servant_3_choice1;

    // Dialog_new(&dialog_bulletin_board);
    // dialog_bulletin_board.text = dialog_bulletin_board_text;
    // dialog_bulletin_board.choice1 = dialog_bulletin_board_choice1;
}

#endif // BASEMENT_SCENE_H
