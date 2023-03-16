//
// Created by holly on 15/03/23.
//

#include "game.h"
#define PORT 25567
#include <utility>


Game::Game() {
    ServerInfo defaultServer;
    defaultServer.port = PORT;
    defaultServer.address = 2130706433;
    defaultServer.name = "A server";

    Map defaultMap;         //Aqua-man drowns in endgame
    defaultMap.width = 0;
    defaultMap.height = 0;

    Game(defaultServer, defaultMap, 1, 0);
}

Game::Game(ServerInfo serverInfo, Map map, int number_of_players, int localPlayerID) {
    this->server = std::move(serverInfo);
    this->map = map;
    this->number_of_players = number_of_players;
    this->localPlayerID = localPlayerID;
}