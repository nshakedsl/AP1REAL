
#include "Server.h"

int main(int argc, char **arg) {
    //validate enough arguments
    if (argc != 3) {
        std::cout << "illegal arguments" << std::endl;
        exit(1);
    }

    try {
        std::string fileName = arg[1];
        const int server_port = atoi(arg[2]);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("error creating socket");
        }
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = htons(server_port);
        if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("error binding socket");
        }
        if (listen(sock, 5) < 0) {
            perror("error listening to a socket");
        }
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            // connection is closed
        } else if (read_bytes < 0) {
            // error
        } else {
            cout << buffer;
        }
        int sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
        close(client_sock);
        return
                0;
    } catch (...) {
        std::cout << "illegal arguments" << std::endl;
        exit(1);
    }


    return 0;
}