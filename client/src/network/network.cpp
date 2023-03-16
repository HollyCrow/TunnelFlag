//
// Created by holly on 15/03/23.
//

#include "network.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <rapidjson/document.h>

Client::Client() {}


bool Client::connect(int ip, int port) {
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = ip;

    if (::connect(sock, (sockaddr *) &server_address, sizeof(server_address)) == -1) {
        std::cerr << "Failed to connect to server\n";
        close(sock);
        sock = -1;
        return 1;
    }


    std::cout << "Connected to socket.\n";
    return 0;
}

void Client::disconnect() {
    close(sock);
}