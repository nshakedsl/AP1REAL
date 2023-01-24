#include <sys/socket.h>
#include <stdexcept>
#include "SocketIO.h"
SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

std::string SocketIO::read() {
    ssize_t bytes = recv(sock,buffer,MAX_SIZE,0);
    if (bytes == 0) {
        return "";
    }
    if(bytes<0){
        throw std::exception();
    }
    size_t len = strlen(buffer);
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

std::string SocketIO::recFromServerSize(int sizeToGet)
{
    char bufferSize[OVERHEAD] = {0}; // for the message
    int expected_data_len = sizeof(bufferSize);
    ssize_t read_bytes = recv(sock, bufferSize, OVERHEAD, 0);
    if (read_bytes == 0)
    {
        // connection is closed
        throw std::runtime_error("connection is closed");
    }
    else if (read_bytes < 0)
    {
        throw std::runtime_error("error");
        // error
    }

    bool flag = false;
    int sizeInput = 0;
    std::string strSize = std::string(bufferSize, sizeToGet);

    if (Solver::isNumberValid(strSize))
    {
        sizeInput = stoi(strSize);
        if (sizeInput < 0)
        {
            throw std::invalid_argument("error");
        }
    }
    else{
        throw std::invalid_argument("error");
    }
    //todo: validate success
    char* inputBuffer = static_cast<char *>(calloc((sizeInput + 1), sizeof(char)));
    read_bytes = recv(sock, inputBuffer, sizeInput + 1, 0);
    if (read_bytes == 0)
    {
        // connection is closed
        throw std::runtime_error("connection is closed");
    }
    else if (read_bytes < 0)
    {
        throw std::runtime_error("error");
        // error
    }
    else if (read_bytes < sizeInput)
    {
        throw std::runtime_error("not all data sent");
        // error
    }
    std::string strRet(buffer);
    return strRet;
}

void SocketIO::sendToServer(std::string &str)
{
    size_t data_len = str.length(),numOfDigits = std::to_string(data_len).length();
    //ADD ZEROS:
    std::string strSent=str;
    // declare a stream object
    std::string str1 = std::to_string(str.length());
    strSent.insert(0, str1); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = OVERHEAD - numOfDigits;
    strSent.insert(0, addZero, '0'); // insert 0 addZero times in position 0;


    int sent_bytes = send(sock, str.c_str(), strSent.length(), 0);
    if (sent_bytes < 0)
    {
        throw std::runtime_error("connection is closed");
        //error
    }
}



const string SessionSocket::RecFromClient(int sizeToGet)
{
    char bufferSize[sizeToGet + 1] = {0}; // for the message
    int read_bytes = recv(client_sock, bufferSize, sizeToGet, 0);

    if (read_bytes == 0)
    {
        throw runtime_error("connection closed");
        // connection is closed
    }
    else if (read_bytes < sizeToGet)
    {
        throw runtime_error("not all data sent");
        // error
    }
    bool flag = false;
    int sizeInput = 0;
    string strSize = string(bufferSize, sizeToGet);

    if (CheckFuncs::isNumeric(strSize))
    {
        sizeInput = stoi(strSize);
        if (sizeInput < 0)
        {
            throw invalid_argument("error");
        }
    }
    else
    {
        throw invalid_argument("error");
    }


    char buffer[sizeInput + 1] = {0};

    read_bytes = recv(client_sock, buffer, sizeInput, 0);
    if (read_bytes == 0)
    {
        throw runtime_error("connection closed");
        // connection is closed
    }
    else if (read_bytes < 0)
    {
        throw invalid_argument("erorr");
    }
    else if (read_bytes < sizeInput)
    {
        throw runtime_error("not all data sent");
        // error
    }
    string strRet(buffer);
    return strRet;
}

void SocketIO::sendSize(const std::string &str)
{
    size_t data_len = str.length();
    size_t numOfDigits = std::to_string(data_len).length();
    //ADD ZEROS:
    std::string strSent=str;
    size_t inputLength = strSent.length();
    // declare a stream object
    std::string str1 = std::to_string(inputLength);
    strSent.insert(0, str1); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = OVERHEAD - numOfDigits; //find out what count digits does
    strSent.insert(0, addZero, '0'); // insert 0 addZero times in position 0;

    //The Main Function Send:
    ssize_t sent_bytes = send(sock, strSent.c_str(), strSent.length(), 0);
    if (sent_bytes < 0)
    {
        perror("error sending to client");
    }
}

