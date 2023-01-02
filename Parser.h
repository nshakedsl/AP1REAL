#ifndef AP1REAL_PARSER_H
#define AP1REAL_PARSER_H

#include "vector"
#include <string>
#include "Parser.h"
#include <vector>
#include <ios>
#include <iostream>
#include <sstream>

class Parser {
    std::vector<std::string> components;
public:
    explicit Parser(const std::string& s);
    bool validInput();
    int getK();
    std::string getDistance();
    std::vector<double> getVector();

};


#endif //AP1REAL_PARSER_H
