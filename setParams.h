
#ifndef AP1REAL_SETPARAMS_H
#define AP1REAL_SETPARAMS_H
#include "Command.h"

class setParams : public Command{
public:
    setParams(Solver *solver, DefaultIO *io);

    void execute() final;
};



#endif //AP1REAL_SETPARAMS_H
