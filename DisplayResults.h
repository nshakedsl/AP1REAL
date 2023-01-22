#ifndef AP1_DISPLAYRESULTS_H
#define AP1_DISPLAYRESULTS_H
#include "Command.h"

//get you all the results (classifications), numbered
class DisplayResults : public Command{

    void execute() final;

public:
    DisplayResults(Solver *solver, DefaultIO *io);
};


#endif //AP1_DISPLAYRESULTS_H
