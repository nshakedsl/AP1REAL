#include <algorithm>
#include "Solver.h"

std::string trim(const std::string &s){
    return s.substr(s.find_first_not_of(' '),s.find_last_not_of(' ') - s.find_first_not_of(' '));
}
bool validDist(const std::string& s){
    return s == "AUC" || s == "MAN" || s == "CHB" || s == "CAN" || s == "MIN";
}
//todo:: add verification that k is smaller than file size
bool isNumber(const std::string& s){
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
        throw std::invalid_argument("invalid value for both");
    }
    int i = s.find_first_of(' ');
    std::string kStr = s.substr(0,i);
    std::string distance = s.substr(i+1,s.length()-i);
    if(!validDist(distance) && !isNumber(kStr))
        throw std::invalid_argument("invalid value for both");
    if(!validDist(distance))
        throw std::invalid_argument("invalid distance");
    if(!isNumber(kStr))
        throw std::invalid_argument("invalid k");
    metric = distance;
    k = std::stoi(kStr);
}
