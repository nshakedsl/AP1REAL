#include <string>
#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <utility>
#include "Server.h"

Server::Server(int port, std::string file) {
    this->port = port;
    this->file = std::move(file);
}

//serves a given client properly
void Server::serve(int client_sock) {
    char buffer[4096];
    //serves a given character
    while (true) {
        int expected_data_len = sizeof(buffer);
        long read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        //empty message signals close connection
        if (read_bytes == 0) {
            close(client_sock);
            return;
            //negative bytes read indicate an error has occurred
        } else if (read_bytes < 0) {
            perror("error reading bytes to client");
            close(client_sock);
            return;
        }
        //everything was fine, check client message
        Parser parser = Parser(buffer);
        if (parser.validInput()) {
            File file1 = File(file);
            Classification classification = Classification(parser.getVector(), parser.getDistance(),
                                                           parser.getK(), file1.getVectors(),
                                                           file1.getClassifications());
            strcpy(buffer, classification.getClassification().c_str());
        } else {
            strcpy(buffer, "invalid input");
        }
        unsigned long bytes_sent = strlen(buffer);
        long sent_bytes = send(client_sock, buffer, bytes_sent, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }
}

void Server::run() {
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
    sin.sin_port = htons(port);
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
            exit(1);
        }
        //serves said socket
        serve(client_sock);
    }


}
