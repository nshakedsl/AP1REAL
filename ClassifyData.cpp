#include "ClassifyData.h"

ClassifyData::ClassifyData() {
    description = "classify data";
}

void ClassifyData::execute() {
    if (solver.getK() == -1) {
        //todo: check what the desired behaviour is for undefined parameters
        io->write("uninitialized parameters\n");
        return;
    }
    if (!solver.beenInitialized()) {
        io->write("data upload please.\n");
        return;
    }
    solver.calculateResults();
    io->write("complete data classifying\n");
}

