//
// Created by holly on 15/03/23.
//

#ifndef TUNNELFLAG_NETWORK_H
#define TUNNELFLAG_NETWORK_H
#include <string>

class Client{
public:
    char buffer[4096];

    Client();

    bool connect(const std::string&, int);
    void send(std::string);
    void listen(); //To be run on seperate thread. Runs on infinite loop
    void disconnect() const;
private:
    int sock; //No touchy.
};

#endif //TUNNELFLAG_NETWORK_H
