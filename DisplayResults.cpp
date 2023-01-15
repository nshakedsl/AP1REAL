#include "DisplayResults.h"

DisplayResults::DisplayResults() {
    description = "display results";
}
//adds the results, numbered one line after another
void DisplayResults::execute() {
    std::string res;
    for (int i = 0; i < solver.getResults().size(); ++i) {
        res += std::to_string(i) + " " + solver.getResults().at(i) + "\n";
    }
    res += "Done.\n";
    io->write(res);
}
