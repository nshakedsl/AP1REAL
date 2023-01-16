#ifndef AP1REAL_CLI_H
#define AP1REAL_CLI_H

#include "Command.h"
#include "map"
class CLI {
public:
    explicit CLI(std::map<int,Command*> commands);
    std::string getDisplay();
private:
    std::string genDisplay();
    std::string display;
    std::map<int,Command*> commands;
};


#endif //AP1REAL_CLI_H
