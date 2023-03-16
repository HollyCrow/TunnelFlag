//
// Created by holly on 15/03/23.
//

#ifndef TUNNELFLAG_OBJECTS_H
#define TUNNELFLAG_OBJECTS_H
#include "../utils/vector2.h"
#include <string>

struct Player{
    std::string name;
    Vector2 position;
    int team;
    Vector2 scale = Vector2(100, 100);
};

#endif //TUNNELFLAG_OBJECTS_H
