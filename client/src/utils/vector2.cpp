//
// Created by holly on 09/03/23.
//

#include "vector2.h"
#include <math.h>


Vector2::Vector2(){
    this->x = 0;
    this->y = 0;
}
Vector2::Vector2(double x, double y){
     this->x = x;
     this->y = y;
}

void Vector2::add(double x, double y){
    this->x += x;
    this->y += y;
}


void Vector2::add(Vector2 addition){
    this->x += addition.x;
    this->y += addition.y;
};

double Vector2::distance(double x, double y){
    return sqrt(
            pow(x - this->x, 2)+
            pow(y - this->y, 2));
}

double Vector2::distance(Vector2 addition){
    return sqrt(
        pow(addition.x - this->x, 2)+
        pow(addition.y - this->y, 2));
}