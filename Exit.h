#ifndef AP1REAL_EXIT_H
#define AP1REAL_EXIT_H
#include "Command.h"

class Exit : public Command{

    void execute() final;

public:
    Exit();
};


#endif //AP1REAL_EXIT_H
