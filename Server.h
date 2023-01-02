#ifndef AP1REAL_SERVER_H
#define AP1REAL_SERVER_H
#include <string>
#include "Parser.h"
#include "Classification.h"
#include "File.h"

class Server {
private:
    int port;
    std::string file;
    void serve(int socket);
public:
    Server(int port,std::string file);
    void run();
};


#endif //AP1REAL_SERVER_H
