//
// Created by holly on 09/03/23.
//

#include "game.h"
#include "../utils/vector2.h"
#include "../utils/keyboard.h"

using namespace std;

extern Keyboard keyboard;
extern int screen_width;
extern int screen_height;

Game::Game() : Game(0, Vector2(100, 50)) {}

Game::Game(int ip, Vector2 map_dimensions) {

    this->width = map_dimensions.x;
    this->height = map_dimensions.y;
    this->ip = ip;
    this->local_player.position = Vector2(0, 0);
    this->players->set_walk_speed(10);
    for (int p = 0; p < player_number; p++) {
        players[p].velocity = Vector2::random_vector2(1).get_multiple(players[p].get_walk_speed());
    }
    for (int h = 0; h < height; h++){
        std::fill_n(map[h], width, 1);
    }
    map[10][30] = 0;
}

void Game::click_event() {
    // Check UI clicking etc

    int global_x = floor((keyboard.mouse[0]+local_player.position.x-(screen_width/2))/scale);
    int global_y = floor((keyboard.mouse[1]+local_player.position.y-(screen_height/2))/scale);
    if (!(0 < global_x < width && 0 < global_y < height))return;
    if (keyboard.mouseclick[0]){
        map[global_x][global_y] = 0;
        printf("leftclick\n");
        keyboard.mouseclick[0] = false;
    }
    if (keyboard.mouseclick[1]){
        map[global_x][global_y] = 1;
        printf("rightclick\n");
        keyboard.mouseclick[1] = false;
    }



}


void Game::update() {
    this->local_player.velocity = keyboard.player_move.get_multiple(local_player.get_walk_speed());
    this->local_player.update_position();
    for (int p = 0; p < player_number; p++) {
        players[p].update_position();
    }
}
