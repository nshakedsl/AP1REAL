#ifndef AP1REAL_DEFAULTIO_H
#define AP1REAL_DEFAULTIO_H


#include <string>

class DefaultIO {

public:
    virtual std::string read();
    virtual void write(const std::string &x);
};


#endif //AP1REAL_DEFAULTIO_H
