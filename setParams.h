
#ifndef AP1REAL_SETPARAMS_H
#define AP1REAL_SETPARAMS_H
#include "Command.h"
#define EMPTY {2,3,0}
class setParams : public Command{
public:
    setParams(Solver *solver, DefaultIO *io);

    void execute() final;
};



#endif //AP1REAL_SETPARAMS_H
