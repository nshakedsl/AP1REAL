#include "Exit.h"

Exit::Exit(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "exit";
}

void Exit::execute() {
    //todo: free avaliable recourses
}
