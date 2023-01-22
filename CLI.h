#ifndef AP1REAL_CLI_H
#define AP1REAL_CLI_H

#include "Command.h"
#include "map"
#include <utility>
#include "UploadFile.h"
#include "Solver.h"
#include "SocketIO.h"
class CLI {
public:
    void start();
    CLI();
    explicit CLI(DefaultIO* io);
    std::string getDisplay();
    void exec(int i);

//todo: destructor kill commands seems problematic
~CLI();

private:
    std::string genDisplay();
    std::string display;
    std::map<int,Command*> commands;
    DefaultIO* io;
};


#endif //AP1REAL_CLI_H
