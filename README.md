# AP1REAL

 To compile the code do the following command:
```
g++ -std=c++11 main.cpp Distances.h Distances.cpp
```

To run the code do the following command:
```
./a.out
```

### **Implementation:**

#### **Milestone 1 A:**
Each of the algorithms has been implemented by following the instructions of the wikipedia page for the algorithm.

#### **Milestone 1 B:**
The csv file is read with fstream and sstream libraries. All the vectors are read from the file and stored in a sorted (by key) multimap in O(n*log(n)) , where the key is the distance from the given vector, and then we iterate over the map and return the k the smallest key values. Thus, the k  closest vectors are returned.

### **Optimisations:** 

#### **Milestone 1 A:**
An optimisation to prevent code reuse has been using a generic algorithm to implement winkowski, euclidian and Manhetten distances. Since they only differ on the power of the vectors and the root, they can be treated as specific cases of a generic algorithm.

#### **Milestone 1 B:**
**The constant p**

We chose a constant p=3 for the algorithm Minkowski.