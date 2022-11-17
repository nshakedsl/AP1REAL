
#include "Distances.h"
#define P 3
#include <cmath>

using namespace std;
// constructor
Distances ::Distances(vector<double> &v1, const vector<double> &v2)
{
    this->v1 = v1;
    this->v2 = v2;
}
// calculate euclidian distance
double Distances::euclidianDistance()
{
    return minkowskiDistanceGeneric(2);
}
// calculate manhatten distance
double Distances::manhattenDistance()
{
    return minkowskiDistanceGeneric(1);
}

//calculate chebyshev distance
double Distances::chebyshevDistance()
{
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (abs(v1[i] - v2[i]) > distance)
            distance = abs(v1[i] - v2[i]);
    }
    return distance;
}
// calculate canberra distance
double Distances::canberraDistance()
{
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += (double)abs(v1[i] - v2[i]) / (double)(abs(v1[i]) + abs(v2[i]));
    }
    return distance;
}
// calculate minkowski distance
double Distances::minkowskiDistance()
{
    return minkowskiDistanceGeneric(P);
}
double Distances::minkowskiDistanceGeneric(int exp)
{
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += pow(abs(v1[i] - v2[i]), exp);
    }
    return pow(distance, 1.0 /exp);
}