
#ifndef AP1_FILE_H
#define AP1_FILE_H


#include <string>
#include "VectorCollection.h"

class File {
    //members
    std::string fileName;
    VectorCollection vectors;
    std::map<std::vector<double>, std::string> classifications;
private:
    bool validDouble(const std::string &s);

public:
    // constructor
    File(std::string fileName);
    VectorCollection getVectors();
    std::map<std::vector<double>, std::string> getClassifications();
};


#endif //AP1_FILE_H
