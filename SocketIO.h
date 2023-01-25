#ifndef AP1REAL_SOCKETIO_H
#define AP1REAL_SOCKETIO_H
#include "DefaultIO.h"
#define SIZE 10
#include <cstring>
class SocketIO : public DefaultIO{
private:
    int sock;
public:
    std::string read() override;
    void write(const std::string &x) override;
    explicit SocketIO(int sock);
};


#endif //AP1REAL_SOCKETIO_H
