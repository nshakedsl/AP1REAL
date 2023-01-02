#include <vector>
#include <ios>
#include <iostream>
#include <sstream>
#include "Parser.h"


// Makes sure the input string is a valid double
bool validDouble(const std::string &s) {
    std::istringstream iss(s);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

// Convert string to vector
std::vector<double> parseString(const std::string &s) {
    int counter = 0;
    int prev = 0;
    std::string temp;
    std::vector<double> v;
    while (counter < s.size()) {
        // if it has reached a space character then cuts the string until the space
        if (s[counter] == ' ') {
            temp = s.substr(prev, counter - prev);
            if (!validDouble(temp)) {
                std::cout << "illegal input";
                exit(1);
            }
            v.push_back(stof(temp));
            prev = counter + 1;
        }
        counter++;
    }
    temp = s.substr(prev, counter - prev);
    if (!validDouble(temp)) {
        std::cout << "illegal input";
        exit(1);
    }
    v.push_back(stof(temp));
    return v;
}

/*
 * input: string
 * output: the 3 supposed components of the given string
 */
std::vector<std::string> parseToComponents(const std::string& s){
    std::vector<std::string> components;
    int prev = -2, cur = -1;
    int size = s.length();
    for(int i = 0; i < size; ++i){
        if(s[i] == ' '){
            prev = cur;
            cur = i;
        }
    }
    if(prev<=0)
        return components;
    components.push_back(s.substr(0,prev));
    components.push_back(s.substr(prev+1,cur-prev));
    components.push_back(s.substr(cur+1,size-cur));

    return components;
}
//initialize a Parser
Parser::Parser(const std::string& s) {
    this->components = parseToComponents(s);
}
//check if the part which is supposed to represent the distance actually represents a valid distance
bool validDist(const std::string& s){
    return s == "AUC" || s == "MAN" || s == "CHB" || s == "CAN" || s == "MIN";
}
//check if the part which is supposed to represent the number k is actually a valid number
bool isNumber(const std::string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}
//input: the string given by the user
//output: whether the input string is a valid input according to the given format
bool Parser::validInput() {
    if(components.size()!=3)
        return false;
    std::vector<double> vector = parseString(components.at(0));
    //check if the vector field is legal vector
    if(vector.empty())
        return false;
    //check if the vector field is a legal distance
    if(!validDist(components.at(1)))
        return false;
    //check if the vector field is a legal number
    return isNumber(components.at(2));
}
//converts the 3rd argument to the k value
int Parser::getK() {
    try {
        return std::stoi(components.at(2));
    }
    catch (...){
        throw std::invalid_argument("illegal string given");
    }
}

std::string Parser::getDistance() {
    try {
        return components.at(1);
    }
    catch (...){
        throw std::invalid_argument("illegal string given");
    }
}

std::vector<double> Parser::getVector() {
    try {
        return parseString(components.at(0));
    }
    catch (...){
        throw std::invalid_argument("illegal string given");
    }
}
