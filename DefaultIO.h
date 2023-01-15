#ifndef AP1REAL_DEFAULTIO_H
#define AP1REAL_DEFAULTIO_H


#include <string>
//a generic representation of the IO
class DefaultIO {

public:
    //read from the IO stream
    virtual std::string read();
    //write to said IO stream
    virtual void write(const std::string &x);
};


#endif //AP1REAL_DEFAULTIO_H
