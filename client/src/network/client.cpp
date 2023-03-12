//
// Created by holly on 12/03/23.
//

#include "client.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

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
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");


    if (::connect(sock, (sockaddr*)&server_address, sizeof(server_address)) == -1) {
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

int TCP::receive() {
    if (sock == -1) {
        cerr << "Not connected to server" << endl;
        return -1;
    }


    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        cerr << "Failed to receive data from server" << endl;
        close(sock);
        sock = -1;
        return -1;
    }
    if (bytes_received == 0) {
        cout << "Server disconnected" << endl;
        close(sock);
        sock = -1;
        return -1;
    }

    cout << "Received " << bytes_received << " bytes from server: " << buffer << endl;
    // Process the received data here

    return bytes_received;
}




