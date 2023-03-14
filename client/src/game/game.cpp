//
// Created by holly on 09/03/23.
//

#include "game.h"
#include "../utils/vector2.h"
#include "../utils/keyboard.h"
#include "../camera/camera.h"
#include "../network/client.h"
#include <rapidjson/document.h>


using namespace std;
using namespace rapidjson;


extern Keyboard keyboard;
extern int screen_width;
extern int screen_height;
extern Camera camera;

Game::Game() : Game(16777343, 25567, Vector2(100, 50)) {}

Game::Game(int ip, int port, Vector2 map_dimensions) {
    this->width = (int) map_dimensions.x;
    this->height = (int) map_dimensions.y;
    this->ip = ip;
    this->port = port;
    this->local_player.position = Vector2(0, 0);
    this->players->set_walk_speed(10);
    this->local_player.scale = Vector2(100, 100);
    this->local_player.set_walk_speed(5);
    this->players[0].velocity = Vector2(1, 1);
    for (int p = 0; p < player_number; p++) {
        players[p].velocity = Vector2::random_vector2(1).get_multiple(players[p].get_walk_speed());
    }
    for (int w = 0; w < width; w++){
        std::fill_n(map[w], height, 1);
    }
    map[10][30] = 0;
}

void Game::Request_server() {
    std::string username = "USERNAME";

    std::string message = "{\n"
                          "    \"PACKETID\": \"PLAYER_MOVE\",\n"
                          "    \n"
                          "    \"DATA\" : {\n"
                          "        \"ID\": 1,"
                          "        \"X\": 67,\n"
                          "        \"Y\": 84\n"
                          "    }\n"
                          "}";
    client.send(message);
}

void Game::Process_server(){
    string raw_json = client.buffer;
    Document document;
    document.Parse(client.buffer);
}


void Game::click_event() {
    // Check UI clicking etc
}

void Game::check_break() {

}

void Game::PLAYER_MOVE(int player, Vector2 position) {
    if (player < player_number){
        players[player].set_position(position);
    }
}

void Game::game_tick() {
    int int_location = local_player.position.x * 100 + local_player.position.y;
    if (int_location == last_local_player_location){
        return;
    }
    std::string player_location_packet = "{\n"
                                         "    \"PACKETID\": \"PLAYER_MOVE\",\n"
                                         "    \n"
                                         "    \"DATA\" : {\n"
                                         "        \"X\": "+to_string(local_player.position.x)+",\n"
                                         "        \"Y\": "+to_string(local_player.position.y)+",\n"
                                         "        \"ID\": "+to_string(local_player_id)+"\n"
                                         "    }\n"
                                         "}";
    client.send(player_location_packet);
    last_local_player_location = int_location;
}



void Game::update() {
    check_break();
    this->local_player.velocity = keyboard.player_move.get_multiple(local_player.get_walk_speed());
    this->local_player.update_position();
    for (int p = 0; p < player_number; p++) {
        players[p].update_position();
    }
}
