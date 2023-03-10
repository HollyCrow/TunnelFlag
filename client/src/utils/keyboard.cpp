//
// Created by holly on 09/03/23.
//
#include "keyboard.h"

#include <iostream>
#include <SDL2/SDL.h>
#include "vector2.h"


#include "../game/game.h"
//Keyboard::Keyboard(bool isit) {
//    this->number = 2;
//    std::cout <<(isit);
//}

extern bool closing;
extern SDL_Event quit;
extern Game game;


Keyboard::Keyboard() {

}


void Keyboard::listen() { //TODO: System for single click detection and for held detection (open inventory vs WASD)
    SDL_PollEvent(&quit);
    if (quit.type == SDL_QUIT) {  // Closes the window, if user stops running
        closing = true;
    }

    if (state[SDL_SCANCODE_D]) { //TODO: Make keybinding hotswap-able from code during runtime.
        this->player_move.x = 1;
    }else if (state[SDL_SCANCODE_A]) {
        this->player_move.x = -1;
    }else{
        this->player_move.x = 0;
    }

    if (state[SDL_SCANCODE_W]) {
        this->player_move.y = -1;
    }else if (state[SDL_SCANCODE_S]) {
        this->player_move.y = 1;
    }else{
        this->player_move.y = 0;
    }
}