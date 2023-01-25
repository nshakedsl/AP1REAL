#include "DownloadRes.h"

DownloadRes::DownloadRes(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "download results";
}

//adds the results, numbered one line after another
void DownloadRes::execute() {
    if (!solver->beenInitialized()) {
        io->write("please upload data\n");
        return;
    }
    if (solver->getResults().empty()) {
        io->write("please classify the data\n");
        return;
    }
    std::string res;
    for (int i = 0; i < solver->getResults().size(); ++i) {
        if (!solver->getResults().at(i).empty())
            res += std::to_string(i+1) + '\t' + solver->getResults().at(i) + "\n";
        else
            res += std::to_string(i+1) + '\t' + "illegal value" + "\n";
    }
    io->write(res);
}
