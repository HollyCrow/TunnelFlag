//
// Created by holly on 09/03/23.
//

#include "game.h"
#include "../utils/vector2.h"


Game::Game(int ip, Vector2 map_dimensions){
    this->width = map_dimensions.x;
    this->height = map_dimensions.y;
    this->ip = ip;
    this->local_player = Player(Vector2(0, 0));
}

void Game::update_positions(){
    this->local_player.update_position();
}

