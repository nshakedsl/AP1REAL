#include "CLI.h"
#include "Exit.h"

CLI::CLI(std::map<int, Command*> commands) {
    this->commands = std::move(commands);
    this->display = this->genDisplay();
}

std::string CLI::genDisplay() {
    std::map<int,Command>::iterator it;
    std::string Display;
    for (auto const& x : commands){
        Display += std::to_string(x.first) + ". " + x.second->getDescription() + "\n";
    }
    return Display;
}

std::string CLI::getDisplay() {
    return display;
}

void CLI::exec(int i) {
    commands.at(i)->execute();
}

CLI::CLI() {
    std::map<int, Command*> Commands;
    auto* solver = new Solver();
    DefaultIO* io = new StandardIO();
    Command* command1 = new UploadFile(solver,io);
    Command* command2 = new UploadFile(solver,io);
    Command* command3 = new UploadFile(solver,io);
    Command* command4 = new UploadFile(solver,io);
    Command* command5 = new UploadFile(solver,io);
    Command* command8 = new Exit();
    Commands.insert({1,command1});
    Commands.insert({2,command2});
    Commands.insert({3,command3});
    Commands.insert({4,command4});
    Commands.insert({5,command5});
    Commands.insert({8,command8});
    this->commands = Commands;
}

CLI::CLI(DefaultIO *io) {
    std::map<int, Command*> Commands;
    auto* solver = new Solver();
    Command* command1 = new UploadFile(solver,io);
    Command* command2 = new UploadFile(solver,io);
    Command* command3 = new UploadFile(solver,io);
    Command* command4 = new UploadFile(solver,io);
    Command* command5 = new UploadFile(solver,io);
    Command* command8 = new Exit();
    Commands.insert({1,command1});
    Commands.insert({2,command2});
    Commands.insert({3,command3});
    Commands.insert({4,command4});
    Commands.insert({5,command5});
    Commands.insert({8,command8});
    this->commands = Commands;
}
