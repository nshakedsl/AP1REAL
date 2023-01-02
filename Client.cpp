#include "Client.h"

//runs the client until
void Client::run() {
    char buffer[4096];
    const char *input;
    int read_bytes;
    int expected_data_len = sizeof(buffer);
    unsigned long data_len;
    long sent_bytes;
    //run until the user sends '-1' which is supposed to represent end of input from the user
    while (true) {
        //get input from user
        //getline(std::cin, input);
        scanf("%[^\n]", buffer);
        //std::cin>>buffer;
        strcpy(buffer,input);
        //input -1 signals that the client is done sending things
        if (strcmp(buffer, "-1") == 0) {
            close(cl_socket);
            break;
        }
        Parser parser = Parser(buffer);
        if(!parser.validInput()) {
            std::cout << "input invalid" << std::endl;
            continue;
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
    }
    this->cl_socket = sock;
}