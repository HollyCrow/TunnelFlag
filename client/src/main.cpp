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


int main() {
    /*  -------------------- Window and game initialisation -------------------------  */
//    printf("\n - Tunnel Flag - \n\n");
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
//    SDL_RenderSetScale(renderer, 1, 1);
//    SDL_SetWindowTitle(window, "\n - Tunnel Flag - \n");
//
//    /*  --------------------------- Texture loading --------------------------------  */
//
//    SDL_Surface *surface = SDL_LoadBMP("assets/background.png");
//    background_texture = SDL_CreateTextureFromSurface(renderer, surface);
//    SDL_FreeSurface(surface);

    std::string message = "hello mate wankers";

    /*  ------------------------------ Main menu -----------------------------------  */

    TCP client;
    client.connect(2130706433, 25567);

    client.send(message);
    client.receive();



    /*  -----------------------------------------------------------------------------  */
//    game.local_player.scale = Vector2(100, 100);
//    game.local_player.set_walk_speed(5);
//    game.players[0].velocity = Vector2(1, 1);
////    std::thread calc_thread(&mover);
//    std::thread keys_thread(&keypress_thread);


//    while (!closing) {
//        camera.draw_game();
//        camera.scale = keyboard.scale;
//    }






    // -- END -- Close resources
    /*  -----------------------------------------------------------------------------  */
//    calc_thread.join();
//    keys_thread.join();

    SDL_DestroyTexture(background_texture);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
