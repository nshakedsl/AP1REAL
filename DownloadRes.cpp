#include "DownloadRes.h"

DownloadRes::DownloadRes() {
    description = "download results";
}

void DownloadRes::execute() {
    std::string res;
    for (int i = 0; i < solver.getResults().size(); ++i) {
        res += std::to_string(i) + " " + solver.getResults().at(i) + "\n";
    }
    io->write(res);
}
