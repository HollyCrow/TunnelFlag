//
// Created by holly on 15/03/23.
//

#include "game.h"
#include "../utils/keyboard.h"
#include "../utils/vector2.h"
#include "../network/network.h"
#define PORT 25567
#include <utility>


extern Keyboard keyboard;
extern Client client;
extern bool closing;

Game::Game() {
//    ServerInfo defaultServer;
//    defaultServer.port = PORT;
//    defaultServer.address = 2130706433;
//    defaultServer.name = "A server";
//
//    Map defaultMap;         //Aqua-man drowns in endgame
//    defaultMap.width = 0;
//    defaultMap.height = 0;
//
//    Game(defaultServer, defaultMap, 1, 0);
}

Game::Game(ServerInfo serverInfo, Map map, int number_of_players, int localPlayerID) {
    this->server = std::move(serverInfo);
    this->map = map;
    this->number_of_players = number_of_players;
    this->localPlayerID = localPlayerID;
}

void Game::ClickEvent() {

}

void Game::update() {
    players[localPlayerID].position.add(keyboard.player_move);

//    for (int p = 0; p < player_number; p++) {
//        players[p].update_position();
//    }
}

void Game::playerMove(int ID, Vector2 new_pos) {
    players[ID].position = new_pos;
}

void Game::sendServerData() {
    while (!closing){
        if (players[localPlayerID].position.x != old_pos.x || players[localPlayerID].position.y != old_pos.y) {
            client.send(""
                        "{\n"
                        "  \"PACKETID\": \"PLAYERMOVE\"\n"
                        "  \"DATA\":{\n"
                        "    \"ID\": " + std::to_string(localPlayerID) + ",\n"
                                                                         "    \"X\": " +
                        std::to_string(players[localPlayerID].position.x) +
                        ",\n" //I should probably just use ` or ' here but I cbb
                        "    \"Y\": " + std::to_string(players[localPlayerID].position.y) + "\n"
                                                                                            "  }\n"
                                                                                            "}"
                                                                                            "");
            old_pos = players[localPlayerID].position;
        }

        SDL_Delay(20);
    }
}





