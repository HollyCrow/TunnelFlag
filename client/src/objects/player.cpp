//
// Created by holly on 09/03/23.
//

#include "player.h"
#include "../utils/vector2.h"

//Player::Player(Vector2 start_location) {
//    this->position = start_location;
//}

Player::Player() {
    this->position = Vector2(10, 10);
    this->scale = Vector2(100, 100);
    this->movable = true;
}
Player::Player(Vector2 start_position) {
    this->position = start_position;
    this->scale = Vector2(100, 100);

    this->movable = true;
}


void Player::set_walk_speed(float new_speed) {
    this->walk_speed = new_speed;
}

float Player::get_walk_speed() {
    return this->walk_speed;
}