
#include "FileIO.h"

std::string FileIO::read() {
    return DefaultIO::read();
}

void FileIO::write(const std::string &x) {
    DefaultIO::write(x);
}

void FileIO::setPath(std::string fileName) {

}
