//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_GAME_H
#define TUNNELFLAG_GAME_H

#include <SDL2/SDL.h>

#include "../utils/vector2.h"
#include "../objects/player.h"


struct playerKeybinds{
    SDL_Scancode up = SDL_SCANCODE_W;
    SDL_Scancode down = SDL_SCANCODE_S;
    SDL_Scancode left = SDL_SCANCODE_A;
    SDL_Scancode right = SDL_SCANCODE_D;
};

struct Keybinds{
    playerKeybinds player;
};

class Game{
public:
    int ip;
    int width;
    int height;
    short map[128][128];
    int player_number = 4;
    Player local_player;
    Player players[4];

    Game(int, Vector2);
    Game();

    void update();

};




#endif //TUNNELFLAG_GAME_H
