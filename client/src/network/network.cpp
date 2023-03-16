//
// Created by holly on 15/03/23.
//

#include "network.h"
#include "../utils/vector2.h"
#include "../game/game.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <rapidjson/document.h>

extern bool closing;
extern Game game;


Client::Client() {}


bool Client::connect(const std::string& ip, int port) {
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        std::cerr << "Failed to create socket\n";
        return false;
    }

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, ip.c_str(), &server_address.sin_addr) != 1) {
        std::cerr << "Invalid IP address\n";
        close(sock);
        return false;
    }

    if (::connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Failed to connect to server\n";
        close(sock);
        return false;
    }

    std::cout << "Connected to server\n";
    return true;
}

void Client::disconnect() const {
    close(sock);
}


void Client::send(std::string message) {
    if (sock == -1) {
        std::cerr << "Not connected to server\n";
        return;
    }
    ::send(sock, message.c_str(), message.size(), 0);

    std::cout << "Sent " << message.length() << " bytes to server\n";//: " << message << endl;
}

void Client::listen() {
    if (sock == -1) {
        std::cerr << "Not connected to server\n";
        return;
    }


    while (!closing){
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            std::cerr << "Failed to receive data from server\n";
            close(sock);
            sock = -1;
            return;
        }
        if (bytes_received == 0) {
            std::cout << "Server disconnected\n";
            close(sock);
            sock = -1;
            return;
        }

        std::cout << "Received " << bytes_received << " bytes from server: " << buffer << "\n";

        rapidjson::Document document;
        document.Parse(buffer);
        if (!document.IsObject()) {
            std::cerr << "JSON is not an object" << std::endl;
            return;
        }
        std::string PACKETID =  document["PACKETID"].GetString();

        std::cout << PACKETID << "\n";





//        if (PACKETID == "PLAYER_MOVE"){
//            rapidjson::Value& x_value = document["DATA"]["X"];
//            rapidjson::Value& y_value = document["DATA"]["Y"];
//
//            Vector2 position(x_value.GetFloat(), y_value.GetFloat());
//
//            rapidjson::Value& ID_value = document["DATA"]["ID"];
//            int id = ID_value.GetInt();
//
//            game.PLAYER_MOVE(id, position);
//        }
    }
}