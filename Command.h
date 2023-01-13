#ifndef AP1REAL_COMMAND_H
#define AP1REAL_COMMAND_H

#include "StandardIO.h"
#include <string>
#include "Solver.h"
class Command {
protected:
    Solver solver;
    std::string description;
    DefaultIO *io = new StandardIO();
public:
    virtual void execute() = 0;
    std::string getDescription();
    std::string read();
    void write(const std::string& msg);
};


#endif //AP1REAL_COMMAND_H
