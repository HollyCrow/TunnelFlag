//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_KEYBOARD_H
#define TUNNELFLAG_KEYBOARD_H

#include <SDL2/SDL.h>
#include <iostream>
#include "vector2.h"


class Keyboard{
public:
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    Vector2 player_move = Vector2(0, 0);




    Keyboard();
    Uint8 *keystate;
    int number;
    void listen();
};

#endif //TUNNELFLAG_KEYBOARD_H
