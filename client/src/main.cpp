//
// Created by holly on 08/03/23.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <thread>

#include "game/game.h"
#include "utils/keyboard.h"
#include "camera/camera.h"

using namespace std;

int screen_width = 1920;
int screen_height = 1080;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Game game(0, Vector2(1, 1));
std::thread render_thread_object;
//SDL_Texture background = NULL;
SDL_Texture *background_texture;
SDL_Event event; // For detecting if window is closed;

bool closing = false;
SDL_Scancode up = SDL_SCANCODE_D;

Keybinds keys; //Keybind object, change to change keybinds of game.
Keyboard keyboard; //TODO: Keyboard controller should be static



void mover(){
    while (!closing) {
        SDL_Delay(10);
        game.update();
    }
}


int main(){
    printf("\n - Tunnel Flag - \n\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer,1,1);
    SDL_SetWindowTitle(window, "\n - Tunnel Flag - \n");
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    /*  -----------------------------------------------------------------------------  */
    SDL_Surface* surface = SDL_LoadBMP("assets/background.png");
    background_texture = SDL_CreateTextureFromSurface( renderer, surface );
    SDL_FreeSurface(surface);

    /*  -----------------------------------------------------------------------------  */
    game.local_player.velocity.x = 1;
    game.local_player.scale = Vector2(100, 100);
    std::thread calc_thread(&mover);
    Camera camera;


    keys.player.up = SDL_SCANCODE_E;




    while (!closing){
        camera.draw_game();
        keyboard.listen(); //TODO: possibly move keyboard listener to different thread?
        camera.scale = keyboard.scale;
    }






    // -- END -- Close resources
    /*  -----------------------------------------------------------------------------  */
    calc_thread.join();

    SDL_DestroyTexture(background_texture);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
