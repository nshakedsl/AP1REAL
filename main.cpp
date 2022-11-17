#include <iostream>
#include <vector>
#include "Distances.h"
#define type long double
using namespace std;
//parses a string into a vector of ints, needs to get a string composed of numbers seperated by spaces
//todo: make sure works with empty string
void printLongDouble(type value, bool val = true){
    if(value-(int)value == 0)
        cout.precision(1);
    else
        cout.precision(16);
    cout << value;
    if (val)
        cout << endl;
}

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
    vector<type> v1 = parseString(input1);
    getline(cin,input2, '\n');
    vector<type> v2 = parseString(input2);
    if(v1.empty()){
        cout<<"empty vector, bye!"<<endl;
        return 0;
    }
    if(v1.size() != v2.size()){
        cout<<"illegal input, bye!"<<endl;
        return 0;
    }
    Distances d= Distances(v1, v2);
    //calculate all distances and print them
    fixed(cout);
    printLongDouble(d.euclidianDistance());
    printLongDouble(d.manhattenDistance());
    printLongDouble(d.chebyshevDistance());
    printLongDouble(d.canberraDistance());
    printLongDouble(d.minkowskiDistance(), false);
    return 0;
}
