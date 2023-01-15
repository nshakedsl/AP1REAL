#ifndef AP1REAL_COMMAND_H
#define AP1REAL_COMMAND_H

#include "StandardIO.h"
#include <string>
#include "Solver.h"
//this class represents a generic representation of a command
class Command {
protected:
    Command() = default;
    //used to run the algorithm and pass the variables between commands
    Solver solver;
    //represents the description of the current command
    std::string description;
    //used to read and write by the command
    DefaultIO *io = new StandardIO();
public:
    //must implement the execution of the command
    virtual void execute() = 0;
    //get the description of the current command
    std::string getDescription();
    ~Command();
};


#endif //AP1REAL_COMMAND_H
