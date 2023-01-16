#include "CLI.h"
#include <utility>

CLI::CLI(std::map<int, Command*> commands) {
    this->commands = std::move(commands);
    this->display = this->genDisplay();
}

std::string CLI::genDisplay() {
    std::map<int,Command>::iterator it;
    std::string Display;
    for (auto const& x : commands){
        Display += std::to_string(x.first) + " ." + x.second->getDescription() + "\n";
    }
    return Display;
}

std::string CLI::getDisplay() {
    return display;
}
