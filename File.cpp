
#include <iostream>
#include <fstream>
#include <sstream>
#include "File.h"
File::File( std::string fileName) {
    this->fileName = fileName;

    std::ifstream myFile(fileName);
    // file not found
    if (!myFile.is_open()) {
        std::cout << "Could not open file, bye!" << std::endl;
        exit(1);
    }
    std::string line;
    VectorCollection vectorsLocal = VectorCollection();
    std::map<std::vector<double>, std::string> classificationsLocal;
    // read file line by line
    while (std::getline(myFile, line)) {
        std::istringstream s(line);
        std::string field;
        std::vector<double> v;
        std::vector<std::string> input;
        // read line field by field
        while (getline(s, field, ',')) {
            input.push_back(field);
        }
        for (int i = 0; i < input.size() - 1; i++) {
            // add field to vector
            if (validDouble(input.at(i))) {
                v.push_back(stof(input.at(i)));
            }
        }
        // finish reading vector, add classification to classifications map
        classificationsLocal.insert(std::pair<std::vector<double>, std::string>(v, input.at(input.size()-1)));
        vectorsLocal.pushVector(v);
    }

    this->vectors = vectorsLocal;
    this->classifications = classificationsLocal;


}

bool File::validDouble(const std::string &s) {
    std::istringstream iss(s);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail(); return false;
}
VectorCollection File::getVectors(){
    return vectors;
}
std::map<std::vector<double>, std::string> File::getClassifications(){
    return classifications;
}
