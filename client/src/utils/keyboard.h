//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_KEYBOARD_H
#define TUNNELFLAG_KEYBOARD_H

#include <SDL2/SDL.h>
#include <iostream>
#include "vector2.h"

struct playerKeybinds {
    SDL_Scancode up = SDL_SCANCODE_W;
    SDL_Scancode down = SDL_SCANCODE_S;
    SDL_Scancode left = SDL_SCANCODE_A;
    SDL_Scancode right = SDL_SCANCODE_D;
};

struct Keybinds {
    playerKeybinds player;
};

class Keyboard{
public:
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    float scale = 1;
    Vector2 player_move = Vector2(0, 0);




    Keyboard();
    Uint8 *keystate;
    int number;
    void listen();
};

#endif //TUNNELFLAG_KEYBOARD_H
