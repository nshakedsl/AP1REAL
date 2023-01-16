#include "Command.h"
std::string Command::getDescription(){
    return description;
}

Command::~Command() {
    delete  io;
}

Command::Command(Solver *solver, DefaultIO *io) {
    this->solver = solver;
    this->io = io;
}
