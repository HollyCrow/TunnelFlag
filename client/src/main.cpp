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

bool closing = false;
float scale = 1;

void closer(){
    SDL_Delay(1000);
    closing = true;
}



int main(){
    printf("\n - Tunnel Flag - \n\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer,1,1);
    SDL_SetWindowTitle(window, "\n - Tunnel Flag - \n");
    /*  -----------------------------------------------------------------------------  */


    std::thread thread_calc_object(&closer);

    Camera camera;

    while (!closing){
        camera.draw_game();
    }


    game.local_player.set_position(Vector2(100, 100));
    game.local_player.scale = Vector2(100, 100);



    // -- END --
    /*  -----------------------------------------------------------------------------  */
    thread_calc_object.join();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
