//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_PLAYER_H
#define TUNNELFLAG_PLAYER_H

#include "../utils/vector2.h"
#include "../utils/color.h"

#include "object.h"


class Player: public Object{
public:
    Player();
    Player(Vector2);

    void set_walk_speed(float);
    float get_walk_speed();




private:
    float walk_speed = 1;


};

#endif //TUNNELFLAG_PLAYER_H
