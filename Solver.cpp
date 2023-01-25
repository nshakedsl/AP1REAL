#include <algorithm>
#include <ios>
#include <sstream>
#include <iostream>
#include "Solver.h"
std::string trim_cr(const std::string& s) {
    auto start = s.find_first_not_of('\r');
    if (start == std::string::npos) {
        return "";
    }
    auto end = s.find_last_not_of('\r');
    return s.substr(start, end - start + 1);
}
bool validDistance(const std::string& s){
    return s == "AUC" || s == "MAN" || s == "CHB" || s == "CAN" || s == "MIN";
}
//todo:: add verification that k is smaller than file size
bool Solver::isNumberValid(const std::string& s){
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return std::stoi(s)>0;
}
bool Solver::isNumberK(const std::string& s){
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return std::stoi(s)>0 && std::stoi(s)<=train.size();
}

bool validDouble(const std::string &s) {
    std::istringstream iss(s);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

void Solver::setTrain(const std::string& s) {
    std::istringstream stream(s);
    std::string line;

    while (std::getline(stream, line)) {
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
        // finish reading vector
        train.insert(std::pair<std::vector<double>, std::string>(v, input.at(input.size()-1)));
    }
}

void Solver::setTest(const std::string& s) {
    std::istringstream stream(s);
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream s(line);
        std::string field;
        std::vector<double> v;
        std::vector<std::string> input;

        // read line field by field
        while (getline(s, field, ',')) {
            input.push_back(trim_cr(field));
        }
        for (int i = 0; i < input.size(); i++) {
            // add field to vector
            if (validDouble(input.at(i))) {
                v.push_back(stof(input.at(i)));
            }
        }
        // finish reading vector push it to test
        test.push_back(v);
    }
}



void Solver::setParams(std::string s) {
    std::size_t first = s.find_first_not_of(' ');
    std::size_t last = s.find_last_not_of(' ');
    s = s.substr(first, (last - first + 1));
    //s = trim(s);
    int count = std::count(s.begin(), s.end(), ' ');
    if(count!=1){
        throw 1;
    }
    int i = s.find_first_of(' ');
    int j = s.find_last_of(' ');
    std::string kStr = s.substr(0,i);
    std::string distance = s.substr(j+1,s.length()-j);
    if(!validDistance(distance) && !isNumberValid(kStr))
        throw 1;
    if(!validDistance(distance))
        throw 2;
    if(!isNumberValid(kStr))
        throw 3;
    metric = distance;
    k = std::stoi(kStr);
    std::cout << "left";
}

int Solver::getK() const {
    return k;
}

std::string Solver::getMetric() {
    return metric;
}
std::map<int, std::string> Solver::getResults() {
    return results;
}

bool Solver::beenInitialized() {
    return !train.empty();
}
//todo: implement results, make sure the order is kept
void Solver::calculateResults() {
    for(int i = 0; i <  test.size(); ++i){
        Classification classification = Classification(test.at(i),getMetric(),getK(),train);
        results.insert({i,classification.getClassification()});
    }
}
