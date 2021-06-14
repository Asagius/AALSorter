#ifndef AALSORTER_TESTER_H
#define AALSORTER_TESTER_H

#include <vector>

using namespace std;

class Tester {
private:
    vector<int> basicOperations;                            // number of operations in basic algorithm
    vector<int> improvedOperations;                         // number of operations in improved algorithm
    vector<int> bfsOperations;

    vector<int> basicTime;                                  // times of execution of basic algorithm
    vector<int> improvedTime;                                  // times of execution of improved algorithm
    vector<int> bfsTime;

public:
    //Tester();
    void tests(int iterations, int size, int step);
    void results(int size, int step);

};


#endif //AALSORTER_TESTER_H
