//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_KEYBOARD_H
#define TUNNELFLAG_KEYBOARD_H

#include <SDL2/SDL.h>
#include <iostream>


class Keyboard{
public:
    SDL_Event event;
    int number;
//    Keyboard(bool);
    void listen();
};

#endif //TUNNELFLAG_KEYBOARD_H
