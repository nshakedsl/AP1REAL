#ifndef AP1REAL_FILEIO_H
#define AP1REAL_FILEIO_H

#include "DefaultIO.h"
#include <fstream>
#include <stdexcept>

class FileIO : public DefaultIO {
    std::string fileName;
public:
    //todo: implement, writing to the given file, or reading from the given file
    //todo: throw exception if an error has occurred

    FileIO() = default;

    //set the path of the fileIO to the given path
    void setPath(std::string path);

    //write to the current path
    // If the function can't open the file it throws exception
    void write(const std::string &x) override;

    //read the entire file
    // If the function can't open the file it throws exception
    std::string read() override;
};

#endif //AP1REAL_FILEIO_H
