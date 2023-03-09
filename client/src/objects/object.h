//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_OBJECT_H
#define TUNNELFLAG_OBJECT_H
#include "../utils/vector2.h"
#include "../utils/color.h"




class Object{
public:
    Vector2 position = Vector2(0,0);
    Vector2 velocity = Vector2(0,0);
    Vector2 scale;
    float rotation;
    Color color = Color(255, 255, 255, 255);
    bool movable;

    Object();
    Object(Vector2, bool);


    Vector2 get_position();
    void set_position(Vector2);
    void move(Vector2);
    void update_position();
};


#endif //TUNNELFLAG_OBJECT_H
