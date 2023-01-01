
#include <vector>
#include <sstream>
#include "Client.h"
#include <iostream>
//todo: extract me
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
    return 0;
}

void Client::run() {
    char buffer[4096];
    int read_bytes;
    int expected_data_len = sizeof(buffer);
    unsigned long data_len;
    long sent_bytes;
    while (true) {
        //get input from user
        //getline(std::cin, buffer);
        std::cin>>buffer;
        //input -1 signals that the client is done sending things
        if (strcmp(buffer, "-1") == 0) {
            close(cl_socket);
            break;
        }
        data_len = strlen(buffer);
        sent_bytes = send(cl_socket, buffer, data_len, 0);
        if (sent_bytes < 0) {
            perror("failed to send to the client");
            break;
        }
        read_bytes = recv(cl_socket, buffer, expected_data_len,0);
        //cuts the communications
        if (read_bytes ==0){
            close(cl_socket);
            break;
        }
        else if (read_bytes < 0){
            perror("error when reading input");
            exit(1);
        }
        else{
            std::cout << buffer;
        }
    }
}

Client::Client(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    // initiate the struct
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip);
    sin.sin_port = htons(port);
    // connect to the server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    this->cl_socket = sock;
}