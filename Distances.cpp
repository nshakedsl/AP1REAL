
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
    long double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += pow(v1[i] - v2[i], 2);
    }
    return sqrt(distance);
}
// calculate manhatten distance
long double Distances::manhattenDistance()
{
    long double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += abs(v1[i] - v2[i]);
    }
    return distance;
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
    long double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += pow(abs(v1[i] - v2[i]), P);
    }
    return pow(distance, 1.0 /P);
}