//
// Created by holly on 09/03/23.
//

#include "game.h"
#include "../utils/vector2.h"
#include "../utils/keyboard.h"

extern Keyboard keyboard;

Game::Game(int ip, Vector2 map_dimensions){
    this->width = map_dimensions.x;
    this->height = map_dimensions.y;
    this->ip = ip;
    this->local_player.position = Vector2(0, 0);




    for (int p = 0; p < player_number; p++){
        players[p].velocity = Vector2::random_vector2(0.000000001);
    }
}



void Game::update(){
    this->local_player.velocity = keyboard.player_move.get_multiple(local_player.get_walk_speed());
    this->local_player.update_position();
    for (int p = 0; p < player_number; p++){
        players[p].update_position();
    }

}

