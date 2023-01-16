#include "Command.h"
class ClassifyData : public Command{
    ClassifyData(Solver *solver, DefaultIO *io);
    void execute() final;
};


