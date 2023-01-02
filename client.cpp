#include <iostream>
#include "Client.h"
int main(int argc, char **arg) {
    //validate enough arguments
    if (argc != 3) {
        std::cout << "illegal arguments" << std::endl;
        exit(1);
    }
    //validate the port
    int port;
    try {
        port = std::stoi(arg[2]);
        if (port > 65535 || port < 1) {
            std::cout << "illegal port" << std::endl;
            exit(1);
        }
    }
        //exit for invalid port
    catch (...) {
        std::cout << "illegal port" << std::endl;
        exit(1);
    }
    //todo: validate ip
    const char *ip_address = "127.0.0.1";
    Client client = Client(ip_address,port);
    client.run();
    return 0;
}