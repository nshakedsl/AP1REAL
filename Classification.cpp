
#include "Classification.h"


// constructor
Classification::Classification(const std::vector<double> &v, std::string distance, int k, VectorCollection vectors, std::map<std::vector<double>, std::string> classifications) {
    this->v = v;
    this->distance = distance;
    this->k = k;
    this->vectors=vectors;
    this->classifications=classifications;
}

std::string Classification::getClassification() {
    //get KClosest
    std::vector<std::vector<double>> kClosest = vectors.getDistancesK(v, distance, k);
    //a map that counts the occurrence of each classification
    std::map<std::string, int> classificationCount;
    //iterates over the k  closest vectors and initializes the map according to their classifications
    for (std::vector<double> vector: kClosest) {
        //if the value is absent in the map, add it
        if (classificationCount.find(classifications[vector]) == classificationCount.end())
            classificationCount.insert(std::pair<std::string, int>(classifications[vector], 1));
            //if the value isn't absent increment it
        else
            classificationCount[classifications[vector]] += 1;
    }
    int max = -1;
    std::string classification = "no classification found";
    //goes over all the counts of each classification to find the most common one
    for (auto &it: classificationCount) {
        //if the current value is larger than the max then set the current value to the max
        // and the string to the current tag
        if (it.second > max) {
            classification = it.first;
            max = it.second;
        }
    }
    return classification;
}

