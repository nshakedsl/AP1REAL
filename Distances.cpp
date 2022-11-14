
#include "Distances.h"
#define P 3
#include <cmath>

using namespace std;
// constructor
Distances ::Distances(vector<long double> &v1, const vector<long double> &v2)
{
    this->v1 = v1;
    this->v2 = v2;
}
// calculate euclidian distance
long double Distances::euclidianDistance()
{
    return minkowskiDistanceGeneric(2);
}
// calculate manhatten distance
long double Distances::manhattenDistance()
{
    return minkowskiDistanceGeneric(1);
}

//calculate chebyshev distance
long double Distances::chebyshevDistance()
{
    long double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (abs(v1[i] - v2[i]) > distance)
            distance = abs(v1[i] - v2[i]);
    }
    return distance;
}
// calculate canberra distance
long double Distances::canberraDistance()
{
    long double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += (long double)abs(v1[i] - v2[i]) / (long double)(abs(v1[i]) + abs(v2[i]));
    }
    return distance;
}
// calculate minkowski distance
long double Distances::minkowskiDistance()
{
    return minkowskiDistanceGeneric(P);
}
long double Distances::minkowskiDistanceGeneric(int exp)
{
    long double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += pow(abs(v1[i] - v2[i]), exp);
    }
    return pow(distance, 1.0 /exp);
}