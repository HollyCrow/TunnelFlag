//
// Created by holly on 12/03/23.
//

#ifndef TUNNELFLAG_CLIENT_H
#define TUNNELFLAG_CLIENT_H
#include <string>

class TCP{
public:
    char buffer[4096];


    TCP();

    void connect(int, int);
    int send(std::string&);
    void receive();

private:
    int sock;
};




#endif //TUNNELFLAG_CLIENT_H
