#ifndef AP1REAL_STANDARDIO_H
#define AP1REAL_STANDARDIO_H
#include "DefaultIO.h"

class StandardIO: public DefaultIO{
    std::string read() override;
    void write(const std::string &x) override;

public:
    StandardIO() = default;
};

#endif //AP1REAL_STANDARDIO_H
