#include <iostream>
#include <vector>
#include "Distances.h"
using namespace std;

bool validDouble(string s){
    bool hadDot = false;
    if(s.empty())
        return false;
    for (int i = 0; i < s.size(); ++i) {
        if(i == 0 && s[i] == '-'){
            continue;
        }
        if(s[i]=='.' && !hadDot) {
            hadDot = true;
            continue;
        }
        if(s[i]<'0'||s[i]>'9')
            return false;
    }
    return true;
}
//parses a string into a vector of ints, needs to get a string composed of numbers seperated by spaces
void printLongDouble(double value, bool val = true){
    if(value-(int)value == 0)
        cout.precision(1);
    else
        cout.precision(16);
    cout << value;
    if (val)
        cout << endl;
}

vector<double> parseString(const string& s){
    int counter = 0;
    int prev = 0;
    string temp;
    vector<double> v;
    while (counter < s.size()){
        // if it has reached a space character then cuts the string until the space
        if(s[counter] == ' '){
            temp = s.substr(prev,counter - prev);
            if(!validDouble(temp)){
                cout << "illegal input";
                exit(1);
            }
            v.push_back(stof(temp));
            prev = counter + 1;
        }
        counter++;
    }
    temp = s.substr(prev,counter - prev);
    if(!validDouble(temp)){
        cout << "illegal input";
        exit(1);
    }
    v.push_back(stof(temp));
    return v;
}


int main() {
    string input1, input2;
    // receives 2 vectors from the user
    getline(cin,input1, '\n');
    vector<double> v1 = parseString(input1);
    getline(cin,input2, '\n');
    vector<double> v2 = parseString(input2);
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
    printLongDouble(d.minkowskiDistance());
    return 0;
}
