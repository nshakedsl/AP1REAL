#include <sys/socket.h>
#include "SocketIO.h"
#define MAX_SIZE 4096
SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

std::string SocketIO::read() {
    ssize_t bytes = recv(sock,buffer,MAX_SIZE,flag);
    if (bytes == 0) {
        return "";
    }
    if(bytes<0){
        throw std::exception();
    }
    return {buffer};
}

void SocketIO::write(const std::string &x) {
    ssize_t bytes = send(sock,x.c_str(),x.length(),0);
    if(bytes < 0)
        throw std::exception();
}
