//
// Created by holly on 15/03/23.
//

#ifndef TUNNELFLAG_NETWORK_H
#define TUNNELFLAG_NETWORK_H
#include <string>

class Client{
public:

    Client();

    bool connect(int, int);
    void send(std::string);
    void listen(); //To be run on seperate thread. Runs on infinite loop
    void disconnect();
private:
    int sock; //No touchy.
};

#endif //TUNNELFLAG_NETWORK_H
