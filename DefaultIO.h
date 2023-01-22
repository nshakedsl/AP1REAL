#ifndef AP1REAL_DEFAULTIO_H
#define AP1REAL_DEFAULTIO_H


#include <string>

//a generic representation of the IO
class DefaultIO {

public:
    //read from the IO stream
    virtual std::string read() = 0;

    //write to said IO stream
    virtual void write(const std::string &x) = 0;
    virtual ~DefaultIO() = 0;
};


#endif //AP1REAL_DEFAULTIO_H
