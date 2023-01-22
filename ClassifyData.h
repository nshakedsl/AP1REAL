#include "Command.h"
class ClassifyData : public Command{
    void execute() final;

public:
    ClassifyData(Solver *solver, DefaultIO *io);
};


