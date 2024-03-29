#include <sys/socket.h>
#include <stdexcept>
#include <sstream>
#include "SocketIO.h"

SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

bool isValidInteger(const std::string &str) {
    std::istringstream ss(str);
    int x;
    ss >> x;
    return !ss.fail() && ss.eof();
}

/*
std::string SocketIO::read() {
    char bufferSize[SIZE + 1] = {0}; // for the message
    int read_bytes = recv(sock, bufferSize, SIZE, 0);
    if (read_bytes == 0) {
        throw std::runtime_error("connection closed");
    } else if (read_bytes < SIZE) {
        throw std::runtime_error("not all data sent");
    }
    int sizeInput = 0;
    std::string strSize = std::string(bufferSize);
    if (isValidInteger(strSize)) {
        sizeInput = stoi(strSize);
        if (sizeInput < 0) {
            throw std::invalid_argument("error");
        }
    } else {
        throw std::invalid_argument("error");
    }
    //TODO: remeber to free !!!
    char* buffer = (char*) calloc(sizeInput + 1, sizeof(char));
    if(buffer==nullptr){
        throw std::invalid_argument("memory allocation failed");
    }
    read_bytes = recv(sock, buffer, sizeInput, 0);
    if (read_bytes == 0) {
        throw std::runtime_error("connection closed");
    } else if (read_bytes < 0) {
        throw std::invalid_argument("error");
    } else if (read_bytes < sizeInput) {
        throw std::runtime_error("not all data sent");
        // error
    }
    std::string strRet(buffer);
    free(buffer);
    return strRet;
}

void SocketIO::write(const std::string &x) {
    //ADD ZEROS:
    std::string strSent=x;
    int inputLength = strSent.length();
    // declare a stream object
    std::string str1 = std::to_string(inputLength);
    strSent.insert(0, str1); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = SIZE - std::to_string(inputLength).length() ;
    strSent.insert(0, addZero, '0'); // insert 0 addZero times in position 0;
    int sent_bytes = send(sock, strSent.c_str(), strSent.length(), 0);
    if (sent_bytes < 0)
    {
        throw std::runtime_error("error sending to socket");
    }
}
 */
void SocketIO::write(const std::string &y) {
    std::string x = y;
    //ADD ZEROS:
    x += DELIM;
    char buffer[CONST + 1];
    size_t len = x.length();
    int index = 0;
    while (len > CONST) {
        len -= CONST;
        strcpy(buffer, x.substr(index, CONST).c_str());
        index += CONST;
        ssize_t sent_bytes = send(sock, buffer, CONST+1, 0);
        if (sent_bytes < 0) {
            throw std::runtime_error("error sending to socket");
        }
    }
    ssize_t sent_bytes = send(sock, x.substr(index).c_str(), strlen(x.substr(index).c_str()) + 1, 0);
    if (sent_bytes < 0) {
        throw std::runtime_error("error sending to socket");
    }

}

std::string SocketIO::read() {
    std::string ret;
    char buffer[CONST + 1] = {0}; // for the message
    char *found;
    ssize_t read_bytes;
    do {
        read_bytes = recv(sock, buffer, CONST+1, 0);
        found = std::find(std::begin(buffer), std::end(buffer), DELIM);
        if (found == std::end(buffer))
            ret += buffer;
        else{
            buffer[strlen(buffer)-1] = '\0';
            ret += buffer;
        }
        if (read_bytes == 0) {
            throw std::runtime_error("connection closed");
        } else if (read_bytes < 0) {
            throw std::runtime_error("error");
        }
    } while (found == std::end(buffer));
    return ret;
}
