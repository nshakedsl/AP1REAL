
#ifndef AP1_DISTANCES_H
#define AP1_DISTANCES_H
#include <vector>
using namespace std;

class Distances {
    //members
    vector<double> v1, v2;
public:
    //constructor
    Distances(vector<double> &v1, const vector<double> &v2);
    //distance functions
    double euclidianDistance();

    double manhattenDistance();

    double chebyshevDistance();

    double canberraDistance();

    double minkowskiDistance();

    double minkowskiDistanceGeneric(int exp);
};

#endif //AP1_DISTANCES_H
