//
// Created by holly on 09/03/23.
//

#include "game.h"
#include "../utils/vector2.h"
#include "../utils/keyboard.h"
#include "../camera/camera.h"

using namespace std;

extern Keyboard keyboard;
extern int screen_width;
extern int screen_height;
extern Camera camera;

Game::Game() : Game(0, Vector2(100, 50)) {}

Game::Game(int ip, Vector2 map_dimensions) {

    this->width = (int) map_dimensions.x;
    this->height = (int) map_dimensions.y;
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
}

void Game::check_break() {

    // I actually wanna kill myself
}



void Game::update() {
    check_break();
    this->local_player.velocity = keyboard.player_move.get_multiple(local_player.get_walk_speed());
    this->local_player.update_position();
    for (int p = 0; p < player_number; p++) {
        players[p].update_position();
    }
}
