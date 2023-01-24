#ifndef AP1REAL_SOCKETIO_H
#define AP1REAL_SOCKETIO_H
#include "DefaultIO.h"
#include "Solver.h"
#define MAX_SIZE 8182
#define OVERHEAD sizeof(int) + 1
#include <cstring>
class SocketIO : public DefaultIO{
private:
    int sock;
    char buffer[MAX_SIZE]{};
    void sendSize(const std::string &str);
public:
    std::string read() override;
    void write(const std::string &x) override;
    explicit SocketIO(int sock);

    std::string recFromServerSize(int sizeToGet);

    void sendToServer(std::string &str);
};


#endif //AP1REAL_SOCKETIO_H
