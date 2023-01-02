#include <string>
#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include "Server.h"

Server::Server(int port,std::string file) {
    this->port = port;
    this->file = file;
}

void Server::serve(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    long read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    } else if (read_bytes < 0) {
        // error
    } else {
        std::cout << buffer;
    }
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
    close(client_sock);
}

void Server::run() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(1);
    }

    while (true){
        if (listen(sock, 5) < 0) {
            perror("error listening to a socket");
            exit(1);
        }
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            exit(1);
        }
        serve(client_sock);
    }


}
