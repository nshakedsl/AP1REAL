#include "Command.h"
std::string Command::getDescription(){
    return description;
}

Command::~Command() {
    delete  io;
}
