#ifndef AP1REAL_COMMAND_H
#define AP1REAL_COMMAND_H
#include "DefaultIO.h"
#include <string>
#include "Solver.h"
//this class represents a generic representation of a command
class Command {
protected:
    Command(Solver *solver, DefaultIO *io);
    //used to run the algorithm and pass the variables between commands
    Solver *solver;
    //represents the description of the current command
    std::string description;
    //used to read and write by the command
    DefaultIO *io;
public:
    //must implement the execution of the command
    virtual void execute() = 0;
    //get the description of the current command
    std::string getDescription();
    virtual ~Command();
};


#endif //AP1REAL_COMMAND_H
