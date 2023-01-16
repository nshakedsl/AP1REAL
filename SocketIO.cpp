#include <sys/socket.h>
#include "SocketIO.h"
#define MAX_SIZE 4096
SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

std::string SocketIO::read() {
    recv(sock,buffer,MAX_SIZE,flag);
    //todo: why the warning???
    return std::string(buffer);
}

void SocketIO::write(const std::string &x) {
    unsigned long length = x.length();
    for (int i = 0; i < length; ++i) {
        buffer[i] = x[i];
    }
    buffer[length] = '\0';
    send(sock,buffer,sizeof (buffer)+1,0);
}
