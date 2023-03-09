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
//std::thread render_thread_object;

void quit(){
//    std::terminate(render_thread_object);

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void render_thread(Camera *camera) {
    while (!camera->close) {
        camera->draw_game();
    }
}



int main(){
    printf("\n - Tunnel Flag - \n\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer,1,1);
    SDL_SetWindowTitle(window, "\n - Tunnel Flag - \n");
    game.local_player.set_position(Vector2(100, 100));
    game.local_player.scale = Vector2(100, 100);
    Camera camera;
    std::thread render_thread_object(&render_thread, &camera);
//    std::terminate(render_thread_object);
    SDL_Delay(5000);
    camera.close = true;
    SDL_Delay(5000);


    return 0;
}
