//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_GAME_H
#define TUNNELFLAG_GAME_H

#include <SDL2/SDL.h>

#include "../utils/vector2.h"
#include "../objects/player.h"
#include "../network/client.h"




class Game {
public:
    int ip;
    int port;
    char server_name[100] = "Sever name";


    int width;
    int height;
    short map[128][128]{};
    const int scale = 100;
    Player local_player;
    Player players[128];
    int player_number;
    TCP client;


    Game(int, int, Vector2);

    Game();

    void Request_server();
    void Process_server();

    void update();

    void click_event();

    void check_break();

    void PLAYER_MOVE(int, Vector2);

};


#endif //TUNNELFLAG_GAME_H
