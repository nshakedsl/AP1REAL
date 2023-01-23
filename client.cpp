#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "thread"
#include <cstring>
#include <mutex>
#include "SocketIO.h"
#include "FileIO.h"

/*
 * attempt to write to the file in the given destination
 * print invalid input if the download failed
 */
void downLoad(const std::string& path,SocketIO socketIo){
    std::mutex m;
    FileIO fileIo = FileIO();
    fileIo.setPath(path);
    std::string input;
    m.lock();
    try {
        input = socketIo.read();
        if(input != "please classify the data" && input != "please upload data")
            fileIo.write(input);
        else
            std::cout << input << std::endl;
    } catch (...){
        std::cout << "invalid input" << std::endl;
    }
    m.unlock();
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
    //initialize the connection
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
    //attempt to connect to the server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(1);
    }
    SocketIO socketIo = SocketIO(sock);
    //talking with the server
    int choice;
    std::string input;
    FileIO fileIo = FileIO();
    std::string options = socketIo.read();
    //run until the user puts 8, signifying the end of the connection to the client
    while (true) {
        std::cout << options;
        getline(std::cin, input);
        //std::cin >> choice;
        //send choice to the user
        socketIo.write(input);
        try {
            choice = std::stoi(input);
        } catch (...){
            std::cout << "invalid input" << std::endl;
            continue;
        }
        switch (choice) {
            //read the given files and write them to the server
            case 1:
                std::cout << socketIo.read();
                getline(std::cin, input);
                //std::cin >> input;
                fileIo.setPath(input);
                try {
                    socketIo.write(fileIo.read());
                    std::cout << socketIo.read() << std::endl;
                } catch (...){
                    socketIo.write("invalid input");
                    std::cout << "invalid input" << std::endl;
                    break;
                }
                std::cin >> input;
                fileIo.setPath(input);
                try{
                    socketIo.write(fileIo.read());
                    std::cout << socketIo.read() << std::endl;
                } catch (...){
                    socketIo.write("invalid input");
                    std::cout << "invalid input" << std::endl;
                }
                break;
            //set KNN for the server
            case 2:
                //get input from user
                std::cout << socketIo.read();
                getline(std::cin, input);
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
                {
                    std::thread thread(downLoad,input,socketIo);
                    thread.detach();
                }
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