
#ifndef AP1REAL_CLIENT_H
#define AP1REAL_CLIENT_H

#include <iostream>
#include <bits/socket.h>
#include <bits/socket_type.h>
#include <sys/socket.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "cstring"

class Client {
private:
    int cl_socket;
public:
    Client(char* ip,int port);
    void run();
};


#endif //AP1REAL_CLIENT_H
