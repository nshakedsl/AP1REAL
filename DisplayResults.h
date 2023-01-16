#ifndef AP1_DISPLAYRESULTS_H
#define AP1_DISPLAYRESULTS_H
#include "Command.h"

//get you all the results (classifications), numbered
class DisplayResults : public Command{
    DisplayResults(Solver *solver, DefaultIO *io);

    void execute() final;
};


#endif //AP1_DISPLAYRESULTS_H
