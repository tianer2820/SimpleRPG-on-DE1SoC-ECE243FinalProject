#if !defined(GLOBAL_H)
#define GLOBAL_H

#include "screen_server/screen_server.h"
#include "input_server/input_server.h"
#include "game_server/game_server.h"

ScreenServer* screen_server;
InputServer* input_server;
GameServer* game_server;

#endif // GLOBAL_H
