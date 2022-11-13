#include <iostream>
#include <vector>
#include <iomanip>
#include "Distances.h"
using namespace std;
//parses a string into a vector of ints, needs to get a string composed of numbers seperated by spaces
//todo: make sure works with empty string
vector<long double> parseString(const string& s){
    int counter = 0;
    int prev = 0;
    vector<long double> v;
    while (counter < s.size()){
        // if it has reached a space character then cuts the string until the space
        if(s[counter] == ' '){
            v.push_back(stof(s.substr(prev,counter)));
            prev = counter + 1;
        }
        counter++;
    }
    v.push_back(stof(s.substr(prev,counter)));
    return v;
}


int main() {
    string input1, input2;
    // receives 2 vectors from the user
    getline(cin,input1, '\n');
    vector<long double> v1 = parseString(input1);
    getline(cin,input2, '\n');
    vector<long double> v2 = parseString(input2);
    if(v1.size() != v2.size()){
        cout<<"illegal input"<<endl;
        return 0;
    }
    Distances d= Distances(v1, v2);
    //calculate all distances and print them
    cout  << setprecision(16);
    cout << d.euclidianDistance() << endl;
    cout << d.manhattenDistance() << endl;
    cout << d.chebyshevDistance() << endl;
    cout << d.canberraDistance() << endl;
    cout << d.minkowskiDistance();
    return 0;
}
