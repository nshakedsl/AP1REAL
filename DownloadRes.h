#ifndef AP1REAL_DOWNLOADRES_H
#define AP1REAL_DOWNLOADRES_H
#include "Command.h"
//get you all the results (classifications), numbered
class DownloadRes : public Command{
    DownloadRes(Solver *solver, DefaultIO *io);

    void execute() final;
};

#endif //AP1REAL_DOWNLOADRES_H
