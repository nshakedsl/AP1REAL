#ifndef AP1REAL_UPLOADFILE_H
#define AP1REAL_UPLOADFILE_H
#include "Command.h"


class UploadFile : public Command{

public:
    UploadFile();

    void execute() final;
};


#endif //AP1REAL_UPLOADFILE_H
