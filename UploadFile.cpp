#include "UploadFile.h"
UploadFile::UploadFile(Solver *solver, DefaultIO *io) : Command(solver, io) {
    description = "upload an unclassified csv data file";
}
//read 2 files from the user
void UploadFile::execute() {
    //reads the input from the user and sets it as the
    io->write("Please upload your local train CSV file.\n");
    std::string input = io->read();
    if(input=="invalid input")
        return;
    solver->setTrain(input);
    io->write("Upload complete.\nPlease upload your local test CSV file.");
    input = io->read();
    if(input=="invalid input")
        return;
    solver->setTest(input);
    io->write("Upload complete.");
}