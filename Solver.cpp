#include <algorithm>
#include "Solver.h"
std::string trim(const std::string &s){
    return s.substr(s.find_first_not_of(' '),s.find_last_not_of(' ') - s.find_first_not_of(' '));
}
bool validDistance(const std::string& s){
    return s == "AUC" || s == "MAN" || s == "CHB" || s == "CAN" || s == "MIN";
}
//todo:: add verification that k is smaller than file size
bool isNumberValid(const std::string& s){
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return std::stoi(s)>0;
}

void Solver::setTrain(const std::string& s) {

}

void Solver::setTest(const std::string& s) {

}
void Solver::setParams(std::string s) {
    s = trim(s);
    int count = std::count(s.begin(), s.end(), ' ');
    if(count!=1){
        throw 1;
    }
    int i = s.find_first_of(' ');
    std::string kStr = s.substr(0,i);
    std::string distance = s.substr(i+1,s.length()-i);
    if(!validDistance(distance) && !isNumberValid(kStr))
        throw 1;
    if(!validDistance(distance))
        throw 2;
    if(!isNumberValid(kStr))
        throw 3;
    metric = distance;
    k = std::stoi(kStr);
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
