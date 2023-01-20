
#ifndef AP1REAL_FILEIO_H
#define AP1REAL_FILEIO_H
#include "DefaultIO.h"

class FileIO : public DefaultIO{


public:
    //todo: implement, writing to the given file, or reading from the given file
    //todo: throw exception if an error has occurred
    FileIO() = default;
    //set the path of the fileIO to the given path
    void setPath(const std::string& fileName);
    //write to the current path
    void write(const std::string &x) override;
    //read the entire file
    std::string read() override;
};


#endif //AP1REAL_FILEIO_H
