#include "ClassifyData.h"

ClassifyData::ClassifyData(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "classify data";
}

void ClassifyData::execute() {
    if (!solver->beenInitialized()) {
        io->write("data upload please.\n");
        return;
    }
    solver->calculateResults();
    io->write("complete data classifying\n");
}

