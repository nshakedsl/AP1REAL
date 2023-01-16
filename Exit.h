#ifndef AP1REAL_EXIT_H
#define AP1REAL_EXIT_H
#include "Command.h"

class Exit : public Command{
    Exit();

    void execute() final;
};


#endif //AP1REAL_EXIT_H
