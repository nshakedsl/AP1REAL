#ifndef AP1REAL_DOWNLOADRES_H
#define AP1REAL_DOWNLOADRES_H
#include "Command.h"
//get you all the results (classifications), numbered
class DownloadRes : public Command{

    void execute() final;

public:
    DownloadRes(Solver *solver, DefaultIO *io);
};

#endif //AP1REAL_DOWNLOADRES_H
