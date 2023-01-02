
#ifndef AP1_CLASSIFICATION_H
#define AP1_CLASSIFICATION_H


#include <vector>
#include <string>
#include "VectorCollection.h"

class Classification {
    // members
    std::vector<double> v;
    std::string distance;
    VectorCollection vectors;
    int k;
    std::map<std::vector<double>, std::string> classifications;

public:
    // constructor
    Classification(const std::vector<double> &v,
                   std::string distance,
                   int k,
                   VectorCollection vectors,
                   std::map<std::vector<double>, std::string> classifications);

    // Classification functions
    std::string getClassification();


};


#endif //AP1_CLASSIFICATION_H
