//
// Created by holly on 09/03/23.
//

#include "camera.h"
#include <SDL2/SDL.h>

#include "../game/game.h"


extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern Game game;
extern int screen_width;
extern int screen_height;



Camera::Camera(){

}


void Camera::rescale_window(int w, int h) {
    SDL_SetWindowSize(window, w, h);
    screen_height = h;
    screen_width = w;
}
