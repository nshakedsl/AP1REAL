#include <cstdio>
#include <iostream>
#include "Server.h"
int main(int argc, char **arg) {
    //validate enough arguments
    if (argc != 3) {
        perror("illegal arguments");
        exit(1);
    }
    //validate the port
    int server_port;
    try {
        server_port = std::stoi(arg[2]);
        if (server_port > 65535 || server_port < 1) {
            perror("illegal port");
            exit(1);
        }
    }
    //exit for invalid port
    catch (...) {
        std::cout << "illegal port" << std::endl;
        exit(1);
    }
    //todo: validate file?
    Server server = Server(server_port,arg[1]);
    server.run();
    return 0;
}