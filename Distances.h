
#ifndef AP1_DISTANCES_H
#define AP1_DISTANCES_H
#include <vector>

using namespace std;

class Distances {
    //members
    vector<long double> v1, v2;
public:
    //constructor
    Distances(vector<long double> &v1, const vector<long double> &v2);
    //distance functions
    long double euclidianDistance();

    long double manhattenDistance();

    long double chebyshevDistance();

    long double canberraDistance();

    long double minkowskiDistance();

    long double minkowskiDistanceGeneric(int exp);
};

#endif //AP1_DISTANCES_H
