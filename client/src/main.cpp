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

int screen_width = 1280;
int screen_height = 960;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Game game(0, Vector2(1, 1));
std::thread render_thread_object;
//SDL_Texture background = NULL;
SDL_Texture *background_texture;


bool closing = false;
float scale = 1;

void closer(){
    SDL_Delay(1000);
    closing = true;
}

void mover(){
    while (!closing) {
        game.update_positions();
    }
}


int main(){
    printf("\n - Tunnel Flag - \n\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer,1,1);
    SDL_SetWindowTitle(window, "\n - Tunnel Flag - \n");
    /*  -----------------------------------------------------------------------------  */
    SDL_Surface* background_image = SDL_LoadBMP("assets/background.png");

    background_texture = SDL_CreateTextureFromSurface( renderer, background_image );




    /*  -----------------------------------------------------------------------------  */
    std::thread stopper_thread(&closer); // For testing only, until keyboard closure actually works;
    std::thread calc_thread(&mover);

    Camera camera;
    //game.local_player.velocity.x = 0.1;

    while (!closing){
        camera.draw_game();
    }


    game.local_player.set_position(Vector2(100, 100));
    game.local_player.scale = Vector2(100, 100);



    // -- END --
    /*  -----------------------------------------------------------------------------  */
    stopper_thread.join();
    calc_thread.join();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
