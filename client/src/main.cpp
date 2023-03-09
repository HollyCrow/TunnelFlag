//
// Created by holly on 08/03/23.
//
#include <iostream>
#include <SDL2/SDL.h>

#include "game/game.h"
#include "utils/keyboard.h"
#include "camera/camera.h"

using namespace std;

int screen_width = 1280;
int screen_height = 960;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Game game(0, Vector2(1, 1));


void quit(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(){
    printf("Starting TunnelFlag...");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer,1,1);
    SDL_SetWindowTitle(window, "Tunnel Flag");

    return 0;
}
