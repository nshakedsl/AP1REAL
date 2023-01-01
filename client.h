//
// Created by ofir on 1/1/23.
//

#ifndef AP1REAL_CLIENT_H
#define AP1REAL_CLIENT_H
#include <iostream>
#include <bits/socket.h>
#include <bits/socket_type.h>
#include <sys/socket.h>

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class client {

};

int main(int argc, char** arg) {
    //validate enough arguments
    if(argc<3) {
        std::cout << "not enough arguments" << std::endl;
        exit(1);
    }
    //validate the port
    int port;
    try{
        port = std::stoi(arg[2]);
        if(port>65535||port<1) {
            std::cout << "illegal port" << std::endl;
            exit(1);
        }
    }
    //exit for invalid port
    catch(...) {
        std::cout << "illegal port" << std::endl;
        exit(1);
    }
    //todo: validate ip
    const char* ip_address = "127.0.0.1";

    int sock = socket(AF_INET, SOCK_STREAM,0);
    if (sock < 0){
        perror("error creating socket");
        exit(1);
    }
    // initiate the struct
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    // connect to the server
    if (connect(sock,(struct sockaddr*)&sin, sizeof(sin))<0)
    {
        perror("error connecting to server");
    }
    char buffer[4096];
    while (true){
        //get input from user
        std::cin >> buffer;
        //input -1 signals that the client is done sending things
        if (strcmp(buffer,"-1") == 0)
            break;
        int data_len = strlen(buffer);
        int sent_bytes = send(sock, buffer, data_len,
                       0);
        if (sent_bytes
            <
            0
                )
        {
// e
    }

    return 0;
}


#endif //AP1REAL_CLIENT_H
