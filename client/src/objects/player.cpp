//
// Created by holly on 09/03/23.
//

#include "player.h"
#include "../utils/vector2.h"

//Player::Player(Vector2 start_location) {
//    this->position = start_location;
//}


void Player::set_walk_speed(float new_speed) {
    this->walk_speed = new_speed;
}

float Player::get_walk_speed() {
    return this->walk_speed;
}