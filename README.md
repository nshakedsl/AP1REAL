# AP1REAL

 To compile the code do the following command:
```
g++ -std=c++11 main.cpp Distances.h Distances.cpp
```

To run the code do the following command:
```
./a.out
```
Implementation and optimisations: each of the algorithms has been implemented by following the instructions of the wikipedia page for the algorithm, an optimisation to prevent code reuse has been using a generic algorithm to implement winkowski, euclidian and Manhetten distances. since they only differ on the power of the vectors and the root in the end they can be just treated as spesific cases of a generic power- n algorithm. 
