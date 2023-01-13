#ifndef AP1REAL_SOLVER_H
#define AP1REAL_SOLVER_H


#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class Solver {
private:
    std::unordered_map<std::string ,std::vector<double>> train;
    std::vector<std::vector<double>> test;
    int k = -1;
    std::string metric;
public:
    Solver() = default;
    //todo::implement setTrain and setTest
    //sets the training file according to the string that represents them
    void setTrain(const std::string& s);
    //sets the test file according to a string that represents them
    void setTest(const std::string& s);
    //sets the KNN params given a string that represents them
    void setParams(std::string s);
};


#endif //AP1REAL_SOLVER_H
