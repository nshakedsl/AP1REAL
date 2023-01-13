#include <iostream>
#include "StandardIO.h"

std::string StandardIO::read() {
    std::string input;
    std::getline(std::cin,input);
    return input;
}

void StandardIO::write(const std::string &x) {
    std::cout << x;
}
