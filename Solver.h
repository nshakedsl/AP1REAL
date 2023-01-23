#ifndef AP1REAL_SOLVER_H
#define AP1REAL_SOLVER_H


#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "Classification.h"
class Solver {
private:
    std::map<std::vector<double>,std::string> train;
    std::vector<std::vector<double>> test;
    int k = 1;
    std::string metric = "AUC";
    std::map<int,std::string> results;
public:
    Solver() = default;
    //todo:implement setTrain and setTest

    //sets the training file according to the string that represents them
    void setTrain(const std::string& s);
    //sets the test file according to a string that represents them
    void setTest(const std::string& s);


    //sets the KNN params given a string that represents them
    void setParams(std::string s);
    //returns the desired K
    int getK() const;
    //returns the desired metric
    std::string getMetric();
    //returns the training set
    void calculateResults();
    static bool isNumberValid(const std::string &string);
    std::map<int,std::string> getResults();
    bool beenInitialized();

};


#endif //AP1REAL_SOLVER_H
