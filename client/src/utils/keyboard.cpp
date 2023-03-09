//
// Created by holly on 09/03/23.
//
#include "keyboard.h"

#include <iostream>
#include <SDL2/SDL.h>

//Keyboard::Keyboard(bool isit) {
//    this->number = 2;
//    std::cout <<(isit);
//}






void Keyboard::listen() { //TODO: System for single click detection and for held detection (open inventory vs WASD)
    while (true) {
        if (SDL_PollEvent(&event)) {
            if (SDL_QUIT == event.type){
                break;
            }
            if (SDL_KEYDOWN == event.type){
                //printf("key is down");
                if (SDLK_a == event.key.keysym.sym){printf(" A pressed \n");}
                if (SDLK_s == event.key.keysym.sym){printf(" S pressed \n");}
                if (SDLK_d == event.key.keysym.sym){printf(" D pressed \n");}
                if (SDLK_w == event.key.keysym.sym){printf(" W pressed \n");}
            }else if (SDL_KEYUP == event.type){
                printf("key is up");
            }
        }
    }
}