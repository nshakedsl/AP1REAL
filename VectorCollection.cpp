#include <vector>
#include "VectorCollection.h"
#include <string>
#include <iostream>
#include "Distances.h"
#include <map>

//add vector to map
void VectorCollection::pushVector(const std::vector<double> &vec) {
    vectorList.push_back(vec);
}

//  TODO: delete before submit!!
void VectorCollection::printVectors() {
    for (std::vector<double> v: vectorList) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v.at(i) << ',';
        }
        cout << endl;
    }
}

std::vector<vector<double>>
VectorCollection::getDistancesK(const std::vector<double> &vector, const std::string &format, int k) {
    //initializes a sorted multimap
    std::multimap<double, std::vector<double>> sortedVecs = getDistances(vector, format);
    //an empty vector of vectors
    std::vector<std::vector<double>> kVectors;
    int counter = 0;
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
        vectors.insert(pair<double, std::vector<double>>(dis, v));
    }
    //returns the list of distance, vector
    return vectors;
}
