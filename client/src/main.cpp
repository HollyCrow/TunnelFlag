//
// Created by holly on 08/03/23.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <thread>

#include "game/game.h"
#include "utils/keyboard.h"
#include "camera/camera.h"
#include "network/client.h"

using namespace std;

int screen_width = 1680;
int screen_height = 1050;
SDL_Window *window = nullptr;       //SDL window and renderer objects
SDL_Renderer *renderer = nullptr;

Game game;                          //Game object, default initialise, does nothing until activated.
Camera camera;                      //Camera object, also does nothing until camera.draw_game() run


SDL_Texture *background_texture;
/*
 * Place other SDL texture objects here
 *
 *
 */


Keybinds keys;                      // Keybind object, change to change keybinds of game.
SDL_Event event;                    // Key events, for single press detection.
Keyboard keyboard;                  // Key object for prolonged detection and SDL_Event parsing

bool closing = false;               // Variable to change to close game, all threads should check this variable to close.

void mover() {
    while (!closing) {
        SDL_Delay(10);
        game.update();
    }
} //Threads
void keypress_thread() { while (!closing) { keyboard.listen(); }}

void packet_listener() {
    game.client.receive();
}


int main() {
    /*  -------------------- Window and game initialisation -------------------------  */
    printf("\n - Tunnel Flag - \n\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1, 1);
    SDL_SetWindowTitle(window, "\n - Tunnel Flag - \n");

    /*  --------------------------- Texture loading --------------------------------  */

//    SDL_Surface *surface = SDL_LoadBMP("assets/background.png");
//    background_texture = SDL_CreateTextureFromSurface(renderer, surface);
//    SDL_FreeSurface(surface);

    /*  ------------------------------ Main menu -----------------------------------  */




    /*  -----------------------------------------------------------------------------  */
    cout << "connecting to server";
    game.client.connect(game.ip, game.port);
    game.Request_server();


    cout << "starting threads\n";
    std::thread calc_thread(&mover);
    std::thread keys_thread(&keypress_thread);
    std::thread packet_thread(&packet_listener);




    while (!closing) {
        camera.draw_game();
        camera.scale = keyboard.scale;
    }






    // -- END -- Close resources
    /*  -----------------------------------------------------------------------------  */
    calc_thread.join();
    keys_thread.join();

    SDL_DestroyTexture(background_texture);

    SDL_DestroyWindow(window);
    SDL_Quit();
    terminate(); //TODO: close packet thread properly

    return 0;
}
