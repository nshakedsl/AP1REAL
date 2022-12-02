#ifndef AP1REAL_VECTORCOLLECTION_H
#define AP1REAL_VECTORCOLLECTION_H

#include <string>
#include <map>


class vectorCollection {
private:
    std::multimap<double, std::vector<double>>
    getDistances(const std::vector<double> &vector, const std::string &format);
public:
    std::vector<std::vector<double>> vectorList;
    //supposed to return the closest k vectors to "vector" according to the calculation type specified in format
    std::vector<std::vector < double>> getDistancesK(const std::vector<double> &vector, const std::string &format, int k);
    //add a new vector to the collection
    void pushVector(const std::vector<double>& vec);
};

#endif //AP1REAL_VECTORCOLLECTION_H
