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
    explicit CLI(std::map<int,Command*> commands);
    CLI();
    explicit CLI(DefaultIO* io);
    std::string getDisplay();
    void exec(int i);
private:
    std::string genDisplay();
    std::string display;
    std::map<int,Command*> commands;
    //todo: destructor kill commands
};


#endif //AP1REAL_CLI_H
