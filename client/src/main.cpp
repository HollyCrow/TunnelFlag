//
// Created by holly on 08/03/23.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <thread>
#include "network/network.h"

using namespace std;

int screen_width = 1920;
int screen_height = 1080;
SDL_Window *window = nullptr;       //SDL window and renderer objects
SDL_Renderer *renderer = nullptr;
SDL_Event event;                    // Key events, for single press detection.

bool closing = false;               // Variable to change to close game, all threads should check this variable to close.


Client client;


int main() {
    /*  -------------------- Window and game initialisation -------------------------  */
    cout << "\nStarting TunnelFlag...\n";
    SDL_GetRendererOutputSize(renderer, &screen_width, &screen_height); //Try to get current screen rez
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1, 1);
    SDL_SetWindowTitle(window, "Tunnel Flag");
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);


    /*  ------------------------------ Main menu -----------------------------------  */





    /*  -----------------------------------------------------------------------------  */


    while(!client.connect(1, 1)){
        cout << "Failed to connect to server, trying again in 500ms\n";
        SDL_Delay(500);
    }
    cout << "Connected to server\n";





    // -- END -- Close resources
    /*  -----------------------------------------------------------------------------  */



    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "Closing...\n";
    return 0;
}
