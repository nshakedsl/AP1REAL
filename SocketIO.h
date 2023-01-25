#ifndef AP1REAL_SOCKETIO_H
#define AP1REAL_SOCKETIO_H
#include "DefaultIO.h"
#define SIZE 10
#define BUFFER_SIZE 4096
#include <cstring>
class SocketIO : public DefaultIO{
private:
    int sock;
    std::string readP();
    void writeP(const std::string &x);
public:
    std::string read() override;
    void write(const std::string &x) override;
    explicit SocketIO(int sock);
};


#endif //AP1REAL_SOCKETIO_H
