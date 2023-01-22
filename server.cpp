#include <cstdio>
#include <iostream>
#include "CLI.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include "thread"

void serve(int sock) {
    DefaultIO *io = new SocketIO(sock);
    CLI cli = CLI(io);
    cli.start();
    delete io;
    close(sock);
}

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
    //CLI cli = CLI();
    //creates the server socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //binds the socket to the given port
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(1);
    }
    //runs forever, continuously serves clients one after another
    while (true) {
        //tries to accept a socket
        if (listen(sock, 5) < 0) {
            perror("error listening to a socket");
            exit(1);
        }
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        //accepts a socket
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        //serves said socket
        std::thread thread(serve, client_sock);
    }
}