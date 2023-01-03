#include "Client.h"
#include <iostream>

void str_copy(char* dest, const std::string& src){
    unsigned long length = src.length();
    for (int i = 0; i < length; ++i) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}
//runs the client until
void Client::run() {
    char buffer[4096];
    int read_bytes;
    int expected_data_len = sizeof(buffer);
    unsigned long data_len;
    long sent_bytes;
    //run until the user sends '-1' which is supposed to represent end of input from the user
    while (true) {
        std::string input;
        //get input from user
        getline(std::cin, input,'\n');
        //scanf("%[^\n]", buffer);
        //std::cin>>buffer;
        str_copy(buffer,input);
        //input -1 signals that the client is done sending things
        if (strcmp(buffer, "-1") == 0) {
            close(cl_socket);
            break;
        }
        std::cout << "buffer: " << buffer << std::endl;
        Parser parser = Parser(buffer);
        if(!parser.validInput()) {
            std::cout << "invalid input" << std::endl;
            continue;
        }
        data_len = strlen(buffer) + 1;
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
            buffer[read_bytes] = '\0';
            std::cout << buffer << std::endl;
        }
    }
}

Client::Client(const char *ip, int port) {
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
        exit(1);
    }
    this->cl_socket = sock;
}
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
    char* ip_address = arg[1];
    Client client = Client(ip_address,port);
    client.run();
    return 0;
}