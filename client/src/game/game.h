//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_GAME_H
#define TUNNELFLAG_GAME_H

#include <SDL2/SDL.h>

#include "../utils/vector2.h"
#include "../objects/player.h"




class Game {
public:
    int ip;
    char server_name[100] = "Sever name";


    int width;
    int height;
    short map[128][128]{};
    int player_number = 4;
    const int scale = 100;
    Player local_player;
    Player players[4];

    Game(int, Vector2);

    Game();

    void update();

    void click_event();

    void check_break();

};


#endif //TUNNELFLAG_GAME_H
