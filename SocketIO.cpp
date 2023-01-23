#include <sys/socket.h>
#include "SocketIO.h"
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
    int len = strlen(buffer);
    if (len < MAX_SIZE || buffer[MAX_SIZE-1] == '\0')
        return {buffer};
    else {
        return buffer + this->read();
    }
}

void SocketIO::write(const std::string &x) {
    size_t len = x.length();
    if(len<MAX_SIZE){
        ssize_t bytes = send(sock,x.c_str(),x.length()+1,0);
        if(bytes < 0)
            throw std::exception();
    } else {
        int current = 0;
        while (current<len){
            ssize_t bytes = send(sock,x.c_str(),x.length()+1,0);
            if(bytes < 0)
                throw std::exception();
            current+=MAX_SIZE;
        }
    }
}
