#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "VectorCollection.h"
#include <map>

using namespace std;

// Makes sure the input string is a valid double
bool validDouble(string s) {
    bool hadDot = false;
    bool hadDigit = false;
    // Loops through the string we received
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 && s[i] == '-') {
            continue;
        }
        if (s[i] == '.' && !hadDot) {
            hadDot = true;
            continue;
        }
        if (s[i] < '0' || s[i] > '9')
            return false;
        hadDigit = true;
    }
    return hadDigit;
}

//parses a string into a vector of ints, needs to get a string composed of numbers seperated by spaces
void printLongDouble(double value, bool val = true) {
    if (value - (int) value == 0)
        cout.precision(1);
    else
        cout.precision(16);
    cout << value;
    if (val)
        cout << endl;
}

// Convert string to vector
vector<double> parseString(const string &s) {
    int counter = 0;
    int prev = 0;
    string temp;
    vector<double> v;
    while (counter < s.size()) {
        // if it has reached a space character then cuts the string until the space
        if (s[counter] == ' ') {
            temp = s.substr(prev, counter - prev);
            if (!validDouble(temp)) {
                cout << "illegal input";
                exit(1);
            }
            v.push_back(stof(temp));
            prev = counter + 1;
        }
        counter++;
    }
    temp = s.substr(prev, counter - prev);
    if (!validDouble(temp)) {
        cout << "illegal input";
        exit(1);
    }
    v.push_back(stof(temp));
    return v;
}

int main(int argc, char **arg) {

    if (argc == 4) {
        int k = atoi(arg[1]);
        string fileName = arg[2];
        string distance = arg[3];
        VectorCollection vectors = VectorCollection();

        std::ifstream myFile(fileName);
        if (!myFile.is_open()) {
            cout << "Could not open file, bye!" << endl;
            exit(1);
        }
        std::string line;
        std::map<std::vector<double>, string> classifications;
        while (std::getline(myFile, line)) {
            std::istringstream s(line);
            std::string field;
            std::vector<double> v;
            while (getline(s, field, ',')) {
                if (validDouble(field)) {
                    v.push_back(stof(field));
                } else {
                    classifications.insert(pair<std::vector<double>, string>(v, field));
                }
            }
            vectors.pushVector(v);
        }
        string input;
        // receives vector from the user
        getline(cin,input, '\n');
        vector<double> v = parseString(input);
        //get KClosest
        vector<vector<double>> kClosest = vectors.getDistancesK(v,distance,k);
        //a map that counts the occurrence of each classification
        map<string,int> classificationCount;
        //iterates over the k closest vectors and initializes the map according to their classifications
        for(vector<double> vector: kClosest){
            //if the value is absent in the map, add it
            if(classificationCount.find(classifications[vector])==classificationCount.end())
                classificationCount.insert(pair<string,int>(classifications[vector],1));
            //if the value isn't absent increment it
            else
                classificationCount[classifications[vector]] += 1;
        }
        int max = -1;
        string classification = "no classification found";
        //goes over all the counts of each classification to find the most common one
        for (auto & it : classificationCount) {
            //if the current value is larger than the max then set the current value to the max
            // and the string to the current tag
            if(it.second>max){
                classification = it.first;
                max = it.second;
            }
        }
        cout << classification;
        // edge case - empty vector
        if(v.empty()){
            cout<<"empty vector, bye!"<<endl;
            return 0;
        }


    } else { // Incorrect number of arguments
        cout << "illegal input, Bye!" << endl;
        exit(1);
    }


    return 0;
}
