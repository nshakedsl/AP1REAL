
#ifndef AP1REAL_CLIENT_H
#define AP1REAL_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "cstring"
#include "Parser.h"

class Client {
private:
    int cl_socket;
public:
    Client(const char* ip,int port);
    void run();
};


#endif //AP1REAL_CLIENT_H
