#include "VectorCollection.h"
#include <string>
#include <iostream>
#include "Distances.h"
#include <map>
#include <utility>

//add vector to map
void VectorCollection::pushVector(const std::vector<double> &vec) {
    vectorList.push_back(vec);
}

std::vector <vector<double>>
VectorCollection::getDistancesK(const std::vector<double> &vector, const std::string &format, int k) {
    //initializes a sorted multimap
    std::multimap<double, std::vector<double>> sortedVecs = getDistances(vector, format);
    //an empty vector of vectors
    std::vector <std::vector<double>> kVectors;
    int counter = 0;
    if (k > vectorList.size() || sortedVecs.empty())
        return kVectors;
    //adds the first k vectors in the map
    for (auto &sortedVec: sortedVecs) {
        if (counter == k)
            break;
        kVectors.push_back(sortedVec.second);
        counter++;
    }
    return kVectors;
}


//calculate the distance of all the vectors according to the chosen method
//we assume that the map is actually created sorted by the key
//returns multimap of distance, vector
std::multimap<double, std::vector<double>>
VectorCollection::getDistances(const std::vector<double> &vector, const std::string &format) {
    //map of vector and distance
    std::multimap<double, std::vector<double>> vectors;
    //iterate over all the vectors
    double dis;
    //iterates over all the vectors
    for (std::vector<double> v: vectorList) {
        //calculate the distance of the current vector with the given one
        try {
            Distances distance = Distances(v, vector);
            if (format == "AUC")
                dis = distance.euclidianDistance();
            else if (format == "MAN")
                dis = distance.manhattenDistance();
            else if (format == "CHB")
                dis = distance.chebyshevDistance();
            else if (format == "CAN")
                dis = distance.canberraDistance();
            else if (format == "MIN")
                dis = distance.minkowskiDistance();
                //illegal type of distance given
            else {
                std::cout << "error" << endl;
                exit(1);
            }
            //inserts the distance of v from the current vector
            vectors.insert(pair < double, std::vector < double >> (dis, v));
        } catch (...) {
            return vectors;
        }

    }
    //returns the list of distance, vector
    return vectors;
}

VectorCollection::VectorCollection(std::vector<std::vector<double>> vectors) {
    vectorList = std::move(vectors);
}
