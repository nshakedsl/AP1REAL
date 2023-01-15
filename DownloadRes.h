#ifndef AP1REAL_DOWNLOADRES_H
#define AP1REAL_DOWNLOADRES_H
#include "Command.h"

class DownloadRes : public Command{
    DownloadRes();

    void execute() final;
};

#endif //AP1REAL_DOWNLOADRES_H
