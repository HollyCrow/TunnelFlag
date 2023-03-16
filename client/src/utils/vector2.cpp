//
// Created by holly on 15/03/23.
//

#include "vector2.h"
#include <cmath>
#include <ctime>
#include <iostream>


Vector2::Vector2() {
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(double x, double y) {
    this->x = x;
    this->y = y;
}


void Vector2::add(double x, double y) {
    this->x += x;
    this->y += y;
}
void Vector2::add(Vector2 addition) {
    this->x += addition.x;
    this->y += addition.y;
};

Vector2 Vector2::get_add(double x, double y) {
    return {this->x + x, this->y + y};
}


Vector2 Vector2::get_add(Vector2 addition) {
    return {this->x + addition.x, this->y + addition.y};
}


void Vector2::minus(double x, double y) {
    this->x -= x;
    this->y -= y;
}


void Vector2::minus(Vector2 addition) {
    this->x -= addition.x;
    this->y -= addition.y;
};


Vector2 Vector2::get_minus(double x, double y) {
    return {this->x - x, this->y - y};
}


Vector2 Vector2::get_minus(Vector2 addition) {
    return {this->x - addition.x, this->y - addition.y};
}


double Vector2::distance(double x, double y) {
    return sqrt(
            pow(x - this->x, 2) +
            pow(y - this->y, 2));
}

double Vector2::distance(Vector2 addition) {
    return sqrt(
            pow(addition.x - this->x, 2) +
            pow(addition.y - this->y, 2));
}

Vector2 Vector2::get_multiple(float scale) {
    return {x * scale, y * scale};
}

Vector2 Vector2::random_vector2(float multiplier) {
    return {((double) rand()) / RAND_MAX, ((double) rand()) / RAND_MAX};
}