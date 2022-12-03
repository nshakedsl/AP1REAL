#ifndef AP1_DISTANCES_H
#define AP1_DISTANCES_H
#include <vector>
using namespace std;

class Distances
{
    // members
    vector<double> v1, v2;

public:
    // constructor
    Distances(vector<double> &v1, const vector<double> &v2);
    // distance functions

    double canberraDistance();

    double manhattenDistance();

    double euclidianDistance();

    double minkowskiDistance();

    double chebyshevDistance();

    double minkowskiDistanceGeneric(int exp);
};

#endif // AP1_DISTANCES_H