
#ifndef AP1REAL_SETPARAMS_H
#define AP1REAL_SETPARAMS_H
#include "Command.h"

class setParams : public Command{
public:
    setParams();

    void execute() final;
};



#endif //AP1REAL_SETPARAMS_H
