#include "DownloadRes.h"

DownloadRes::DownloadRes(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "download results";
}
//adds the results, numbered one line after another
void DownloadRes::execute() {
    std::string res;
    for (int i = 0; i < solver->getResults().size(); ++i) {
        res += std::to_string(i) + '\t' + solver->getResults().at(i) + "\n";
    }
    io->write(res);
}
