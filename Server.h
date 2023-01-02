#ifndef AP1REAL_SERVER_H
#define AP1REAL_SERVER_H
#include <string>

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
