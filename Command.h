#ifndef AP1REAL_COMMAND_H
#define AP1REAL_COMMAND_H

#include "StandardIO.h"
#include <string>
#include "Solver.h"
class Command {
protected:
    Command() = default;
    Solver solver;
    std::string description;
    DefaultIO *io = new StandardIO();
public:
    virtual void execute() = 0;
    std::string getDescription();
};


#endif //AP1REAL_COMMAND_H
