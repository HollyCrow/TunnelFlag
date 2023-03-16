//
// Created by holly on 08/03/23.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <thread>
#include "network/network.h"
#include "game/game.h"
#include "camera/camera.h"
#include "utils/keyboard.h"

using namespace std;

int screen_width = 1920;
int screen_height = 1080;
SDL_Window *window = nullptr;       //SDL window and renderer objects
SDL_Renderer *renderer = nullptr;
SDL_Event event;                    // Key events, for single press detection.

bool closing = false;               // Variable to change to close game, all threads should check this variable to close.


Client client;
Game game;
Keyboard keyboard;
Keybinds keys;
Camera camera;

void network_listen_thread_function(){
    std::string message = "init";
    client.send(message);
    client.listen();
}
void network_send_thread_function(){
    game.sendServerData();
}

void keyboard_thread_function(){
    while(!closing){
        keyboard.listen();
        camera.scale = keyboard.scale;
    }
}

void physics_thread_function(){
    while (!closing){
        game.update();
        SDL_Delay(5);
    }
}



int main() {
    /*  -------------------- Window and game initialisation -------------------------  */
    cout << "\nStarting TunnelFlag...\n";
    SDL_GetRendererOutputSize(renderer, &screen_width, &screen_height); //Try to get current screen rez
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1, 1);
    SDL_SetWindowTitle(window, "Tunnel Flag");
//    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);


    /*  ------------------------------ Main menu -----------------------------------  */

    /*  -------------------------- Connect to server -------------------------------  */

    thread keyboard_thread(&keyboard_thread_function);
    cout << "Connecting to server...\n";
//    client.connect("127.0.0.1", 25567);
    while(!client.connect("127.0.0.1", 25567) && !closing){
        cout << "Failed to connect to server, trying again in 500ms\n";
        SDL_Delay(500);
    }
    cout << "Connected to server\n";
    thread network_listen_thread(&network_listen_thread_function);
    thread network_send_thread(&network_send_thread_function);
    thread physics_thread(&physics_thread_function);



    /*  -------------------------------- Game -------------------------------------  */


    while (!closing){
        camera.draw_game();
    }




    // -- END -- Close resources
    /*  -----------------------------------------------------------------------------  */



    physics_thread.join();
    keyboard_thread.join();
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "Closing...\n";
    client.disconnect();
    network_listen_thread.join();
//    terminate();
    return 0;
}
