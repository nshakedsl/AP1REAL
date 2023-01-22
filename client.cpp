#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "thread"
#include <cstring>
#include "SocketIO.h"
#include "FileIO.h"

bool validPath(const std::string& path){
    return true;
}
void downLoad(const std::string& path,SocketIO socketIo){
    FileIO fileIo = FileIO();
    fileIo.setPath(path);
    fileIo.write(socketIo.read());
}

int main(int argc, char **arg) {
    //initialization routine

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
    char* ip_address = arg[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    SocketIO socketIo = SocketIO(sock);
    //talking with the server
    int choice;
    std::string input;
    FileIO fileIo = FileIO();
    while (true) {
        std::cout << socketIo.read();
        std::cin >> choice;
        socketIo.write(std::to_string(choice));
        switch (choice) {
            case 1:
                std::cout << socketIo.read() << std::endl;
                std::cin >> input;
                fileIo.setPath(input);
                socketIo.write(fileIo.read());
                std::cout << socketIo.read() << std::endl;
                std::cin >> input;
                fileIo.setPath(input);
                socketIo.write(fileIo.read());
                std::cout << socketIo.read() << std::endl;
                break;
            //set KNN for the server
            case 2:
                //get input from user
                std::cout << socketIo.read();
                getline(std::cin, input,'\n');
                socketIo.write(input);
                input = socketIo.read();
                if(input != "OK")
                    std::cout << input;
                break;
            case 3:
            case 4:
                std::cout << socketIo.read();
                break;
            case 5:
                std::cin >> input;
                if(validPath(input)){
                    std::thread thread(downLoad,input,socketIo);
                } else {
                    std::cout << "invalid input" << std::endl;
                }
                //todo: implement me
                break;
            case 8:
                //todo: free all
                close(sock);
                return 0;
            default:
                std::cout << "invalid input" << std::endl;
        }
    }
}