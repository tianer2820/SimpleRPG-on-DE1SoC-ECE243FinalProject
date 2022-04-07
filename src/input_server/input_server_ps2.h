#if !defined(INPUT_SERVER_PS2_H)
#define INPUT_SERVER_PS2_H

#include "../const.h"
#include "input_server.h"
#include "scan_code.h"

#define SCAN_CODE_MAX 512

typedef struct
{
    InputServer base;
    unsigned char key_status[SCAN_CODE_MAX / 8 + 1];
    bool break_code;
    bool extend_code;
} InputServerPS2;



void InputServerPS2_set_key_state(InputServerPS2 *self, KeyScancode k_code, bool state)
{
    if (k_code >= SCAN_CODE_MAX)
        return;
    int byte_offset = k_code / 8;
    int bit_offset = 7 - k_code % 8;

    unsigned char mask = 1 << bit_offset;
    if (state)
    {
        self->key_status[byte_offset] |= mask;
    }
    else
    {
        mask = ~mask;
        self->key_status[byte_offset] &= mask;
    }
}



void InputServerPS2_init(InputServerPS2 *self)
{
    int i;
    for (i = 0; i < SCAN_CODE_MAX / 8 + 1; i++)
    {
        self->key_status[i] = 0;
    }
}
void InputServerPS2_update(InputServerPS2 *self)
{
    volatile int *PS2_ptr = (int *)PS2_BASE; // PS/2 port address
    int PS2_data, RVALID;
    unsigned char byte;
    while (1)
    {
        PS2_data = *(PS2_ptr);        // read the Data register in the PS/2 port
        RVALID = (PS2_data & 0x8000); // extract the RVALID field
        if (RVALID != 0)
        {
            byte = PS2_data & 0xFF;
        } else{
            break;  // no more byte to read
        }

        // state machine
        switch (byte)
        {
        case 0xF0: // break code
            self->break_code = true;
            break;
        case 0xE0: // extend code
            self->extend_code = true;
            break;

        // only WASD, F, Space and Esc are implemented currently
        case 0x1D: // W
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_W, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_W, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        case 0x1C: // A
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_A, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_A, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        case 0x1B: // S
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_S, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_S, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        case 0x23: // D
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_D, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_D, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        case 0x2B: // F
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_F, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_F, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        case 0x76: // Esc
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_ESCAPE, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_ESCAPE, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        case 0x29: // Space
            if (self->break_code)
                InputServerPS2_set_key_state(self, K_SCANCODE_SPACE, false);
            else
                InputServerPS2_set_key_state(self, K_SCANCODE_SPACE, true);
            self->extend_code = false;
            self->break_code = false;
            break;

        default:
            self->extend_code = false;
            self->break_code = false;
            break;
        }
    }
}
void InputServerPS2_stop(InputServerPS2 *self)
{
    // todo
}
bool InputServerPS2_key_is_pressed(InputServerPS2 *self, KeyScancode key)
{
    if (key >= SCAN_CODE_MAX)
        return false;
    int byte_offset = key / 8;
    int bit_offset = 7 - key % 8;
    bool state = (self->key_status[byte_offset] & (1 << bit_offset)) >> bit_offset;
    return state;
}

InputServerPS2 *InputServerPS2_new(InputServerPS2 *self)
{
    InputServerPS2 *server = self;
    if (server == NULL)
    {
        server = (InputServerPS2 *)calloc(1, sizeof(InputServerPS2));
    }
    InputServer_new((InputServer *)server);
    server->base.init = InputServerPS2_init;
    server->base.update = InputServerPS2_update;
    server->base.stop = InputServerPS2_stop;
    server->base.key_is_pressed = InputServerPS2_key_is_pressed;
    return server;
}

#endif // INPUT_SERVER_PS2_H
