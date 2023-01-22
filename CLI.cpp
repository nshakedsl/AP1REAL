#include "CLI.h"
#include "Exit.h"

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
    DefaultIO* pIo = new StandardIO();
    this->io = pIo;
    Command* command1 = new UploadFile(solver, pIo);
    Command* command2 = new UploadFile(solver, pIo);
    Command* command3 = new UploadFile(solver, pIo);
    Command* command4 = new UploadFile(solver, pIo);
    Command* command5 = new UploadFile(solver, pIo);
    Command* command8 = new Exit(nullptr, nullptr);
    Commands.insert({1,command1});
    Commands.insert({2,command2});
    Commands.insert({3,command3});
    Commands.insert({4,command4});
    Commands.insert({5,command5});
    Commands.insert({8,command8});
    this->commands = Commands;
    this->display = this->genDisplay();
}

CLI::CLI(DefaultIO *io) {
    std::map<int, Command*> Commands;
    this->io = io;
    auto* solver = new Solver();
    Command* command1 = new UploadFile(solver,io);
    Command* command2 = new UploadFile(solver,io);
    Command* command3 = new UploadFile(solver,io);
    Command* command4 = new UploadFile(solver,io);
    Command* command5 = new UploadFile(solver,io);
    Command* command8 = new Exit(nullptr, nullptr);
    Commands.insert({1,command1});
    Commands.insert({2,command2});
    Commands.insert({3,command3});
    Commands.insert({4,command4});
    Commands.insert({5,command5});
    Commands.insert({8,command8});
    this->commands = Commands;
    this->display = this->genDisplay();
}

void CLI::start() {
    int choice = -1;
    std::string input;
    //read input until user ends connection with choice = 8
    while (choice != 8) {
        //send to the user all the available commands and wait for his choice
        io->write(this->getDisplay());
        input = io->read();
        //check if number
        //call for function that checks if string is number
        choice = -1;
        try {
            if (Solver::isNumberValid(input)) {
                choice = std::stoi(input);
                if ((choice < 6 && choice > 0) || choice == 8){
                    this->exec(choice);
                }
                else
                    io->write("invalid input");
            }
            else
                io->write("invalid input");
        } catch (...){
            io->write("invalid input");
        }

    }
}
//todo: find if problematic
CLI::~CLI() {
    for (auto const& x : this->commands){
        delete x.second;
    }
}
