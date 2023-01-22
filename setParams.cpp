#include "setParams.h"
setParams::setParams(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "algorithm settings";
}

void setParams::execute() {
    //send the user the KNN parameters
    io->write("The current KNN parameters are: K = " + std::to_string(solver->getK()) + ", distance metric = "
              + solver->getMetric()+"\n");
    std::string str = io->read();
    //if \n is entered the user doesn't want to change the parameters
    if(str=="\n")
        return;
    try {//try to set the parameters
        solver->setParams(str);
    } catch (int i){
        if(i==1) {
            io->write("invalid value for K\ninvalid value for metric\n");
        } else if (i==2) {
            io->write("invalid value for metric\n");
        } else {
            io->write("invalid value for K\n");
        }
    }
}

