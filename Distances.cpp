#include "Distances.h"
#define P 3
#include <cmath>

using namespace std;
// constructor
Distances ::Distances(vector<double> &v1, const vector<double> &v2)
{
    if(v1.size()!=v2.size()){
        throw std::invalid_argument("vectors are not equal");
    }
    this->v1 = v1;
    this->v2 = v2;
}

// calculate canberra distance
double Distances::canberraDistance()
{
    if (v1.empty())
        return 0;
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += (double)abs(v1[i] - v2[i]) / (double)(abs(v1[i]) + abs(v2[i]));
    }
    return distance;
}

// calculate chebyshev distance
double Distances::chebyshevDistance()
{
    if (v1.empty())
        return 0;
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (abs(v1[i] - v2[i]) > distance)
            distance = abs(v1[i] - v2[i]);
    }
    return distance;
}

// calculate manhatten distance
double Distances::manhattenDistance()
{
    return minkowskiDistanceGeneric(1);
}

// calculate euclidian distance
double Distances::euclidianDistance()
{
    return minkowskiDistanceGeneric(2);
}

// calculate minkowski distance
double Distances::minkowskiDistance()
{
    return minkowskiDistanceGeneric(P);
}

// Generic implemention of minkowski distance
double Distances::minkowskiDistanceGeneric(int exp)
{
    if (v1.empty())
        return 0;
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += pow(abs(v1[i] - v2[i]), exp);
    }
    return pow(distance, 1.0 / exp);
}