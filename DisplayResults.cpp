#include "DisplayResults.h"

DisplayResults::DisplayResults(Solver *solver, DefaultIO *io) : Command(solver, io)  {
    description = "display results";
}
//adds the results, numbered one line after another
void DisplayResults::execute() {
    std::string res;
    if(!solver->beenInitialized()){
        io->write("please upload data");
        return;
    }
    if(solver->getResults().empty()){
        io->write("please classify the data");
        return;
    }
    for (int i = 0; i < solver->getResults().size(); ++i) {
        if(!solver->getResults().at(i).empty())
            res += std::to_string(i) + '\t' + solver->getResults().at(i) + "\n";
        else
            res += std::to_string(i) + '\t' + "illegal value" + "\n";
    }
    res += "Done.\n";
    io->write(res);
}
