//
// Created by holly on 12/03/23.
//

#include "client.h"
#include "../game/game.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <rapidjson/document.h>

extern Game game;
extern bool closing;

using namespace std;

TCP::TCP() {}

void TCP::connect(int ip_address, int port) {
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        cerr << "Failed to create socket" << endl;
        return;
    }

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = ip_address;//inet_addr("127.0.0.1");


    if (::connect(sock, (sockaddr *) &server_address, sizeof(server_address)) == -1) {
        cerr << "Failed to connect to server" << endl;
        close(sock);
        sock = -1;
        return;
    }

    cout << "Connected to socket.\n";
}

int TCP::send(string &message) {
    if (sock == -1) {
        cerr << "Not connected to server" << endl;
        return -1;
    }
    ::send(sock, message.c_str(), message.size(), 0);

    cout << "Sent " << message.length() << " bytes to server: " << message << endl;
    return 0;
}

void TCP::receive() {
    if (sock == -1) {
        cerr << "Not connected to server" << endl;
        return;
    }


    while (!closing){
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            cerr << "Failed to receive data from server" << endl;
            close(sock);
            sock = -1;
            return;
        }
        if (bytes_received == 0) {
            cout << "Server disconnected" << endl;
            close(sock);
            sock = -1;
            return;
        }

        cout << "Received " << bytes_received << " bytes from server: " << buffer << endl;
        rapidjson::Document document;
        document.Parse(buffer);
        string PACKETID =  document["PACKETID"].GetString();


        if (PACKETID == "PLAYER_MOVE"){
            rapidjson::Value& x_value = document["DATA"]["X"];
            rapidjson::Value& y_value = document["DATA"]["Y"];

            Vector2 position(x_value.GetFloat(), y_value.GetFloat());

            rapidjson::Value& ID_value = document["DATA"]["ID"];
            int id = ID_value.GetInt();

            game.PLAYER_MOVE(id, position);
        }
    }
}




