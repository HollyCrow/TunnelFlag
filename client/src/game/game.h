//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_GAME_H
#define TUNNELFLAG_GAME_H

#include "../utils/vector2.h"
#include "../objects/player.h"


class Game{
public:
    int ip;
    int width;
    int height;
    short map[128][128];
    Player local_player;
    Player players[0]; // Redundant until multiplayer is implemented, so left at 0.

    Game(int, Vector2);

    void update_positions();

};




#endif //TUNNELFLAG_GAME_H
