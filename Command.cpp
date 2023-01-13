#include "Command.h"
std::string Command::getDescription(){
    return description;
}

std::string Command::read() {
    return io->read();
}

void Command::write(const std::string& msg) {
    io->write(msg);
}
