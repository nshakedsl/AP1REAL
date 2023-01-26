#ifndef AP1REAL_SOCKETIO_H
#define AP1REAL_SOCKETIO_H
#include "DefaultIO.h"
#define SIZE 10
#include <cstring>
#include "algorithm"
#define CONST 4096
#define DELIM '%'
class SocketIO : public DefaultIO{
private:
    int sock;
public:
    std::string read() override;
    void write(const std::string &y) override;
    explicit SocketIO(int sock);
};


#endif //AP1REAL_SOCKETIO_H
