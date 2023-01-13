#include "UploadFile.h"
UploadFile::UploadFile(){
    description = "upload an unclassified csv data file";
}

void UploadFile::execute() {
    //reads the input from the user and sets it as the
    io->write("Please upload your local train CSV file.\n");
    solver.setTrain(io->read());
    io->write("Upload complete.\nPlease upload your local test CSV file.\n");
    solver.setTest(io->read());
    io->write("Upload complete.\n");
}