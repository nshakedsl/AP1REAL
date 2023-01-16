#ifndef AP1REAL_SOCKETIO_H
#define AP1REAL_SOCKETIO_H
#include "DefaultIO.h"
#define MAX_SIZE 4096
class SocketIO : public DefaultIO{
private:
    int flag = 0;
    int sock;
    char buffer[MAX_SIZE]{};
    int expectedLen = MAX_SIZE;
public:
    std::string read() override;
    void write(const std::string &x) override;

    explicit SocketIO(int sock);
};


#endif //AP1REAL_SOCKETIO_H
