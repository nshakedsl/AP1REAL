#include "ClassifyData.h"

ClassifyData::ClassifyData(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "classify data";
}

void ClassifyData::execute() {
    if (!solver->beenInitialized()) {
        io->write("please upload data\n");
        return;
    }
    solver->calculateResults();
    io->write("classifying data complete\n");
}

