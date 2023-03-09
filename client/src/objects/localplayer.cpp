//
// Created by holly on 09/03/23.
//

#include "localplayer.h"
#include "player.h"


LocalPlayer::LocalPlayer() {
    this->position = Vector2(0, 0);
    this->movable = false;
}
LocalPlayer::LocalPlayer(Vector2 start_position) {
    this->position = start_position;
    this->movable = true;
}