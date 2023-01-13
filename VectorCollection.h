
#include <string>
#include <map>
#include <vector>

class VectorCollection {
private:
    std::multimap<double, std::vector<double>>
    getDistances(const std::vector<double> &vector, const std::string &format);
public:
    VectorCollection()=default;
    explicit VectorCollection(std::vector<std::vector<double>> vectors);
    std::vector<std::vector<double>> vectorList;
    //supposed to return the closest k vectors to "vector" according to the calculation type specified in format
    std::vector<std::vector < double>> getDistancesK(const std::vector<double> &vector, const std::string &format, int k);
    //add a new vector to the collection
    void pushVector(const std::vector<double>& vec);
};
