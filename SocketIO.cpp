#include <sys/socket.h>
#include <stdexcept>
#include <sstream>
#include "SocketIO.h"
SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

bool isValidInteger(const std::string& str) {
    std::istringstream ss(str);
    int x;
    ss >> x;
    return !ss.fail() && ss.eof();
}



std::string SocketIO::readP() {
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

void SocketIO::writeP(const std::string &x) {
    //ADD ZEROS:
    std::string strSent=x;
    int inputLength = strSent.length();
    // declare a stream object
    std::string str1 = std::to_string(inputLength);
    strSent.insert(0, str1); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = SIZE - std::to_string(inputLength).length();
    strSent.insert(0, addZero, '0'); // insert 0 addZero times in position 0;
    int sent_bytes = send(sock, strSent.c_str(), strSent.length(), 0);
    if (sent_bytes < 0)
    {
        throw std::runtime_error("error sending to socket");
    }

}

std::string SocketIO::read() {
    int lenToRead = 0;
    std::string whatSent;
    try {
        lenToRead = std::stoi(readP());
    } catch (...){
        throw std::invalid_argument("error with the sockets");

    }
    while (lenToRead > BUFFER_SIZE-1){
        lenToRead-=BUFFER_SIZE - 1;
        whatSent += readP();
    }
    whatSent +=readP();
    return whatSent;
}

void SocketIO::write(const std::string &x) {
    int inputLength = x.length();
    /*std::string lenStr = std::to_string(inputLength);
    int addZero = SIZE - std::to_string(inputLength).length();
    lenStr.insert(0, addZero, '0'); // insert 0 addZero times in position 0;
    int sent_bytes = send(sock, lenStr.c_str(), lenStr.length()+1, 0);
    if (sent_bytes < 0){
        throw std::runtime_error("error sending to socket");
    }*/
    writeP(std::to_string(x.length()));
    int curentChar = 0;
    while (inputLength > BUFFER_SIZE - 1){
        inputLength -= BUFFER_SIZE - 1;
        curentChar += BUFFER_SIZE - 1;
        writeP(x.substr(curentChar,BUFFER_SIZE-2));
    }
    writeP(x.substr(curentChar));
}
