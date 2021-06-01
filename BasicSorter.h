//
// Created by Asagius on 01.06.2021.
//

#ifndef AALSORTER_BASICSORTER_H
#define AALSORTER_BASICSORTER_H


#include <vector>
using namespace std;

class BasicSorter {
private:
    int counter, first, second, third, fourth;

public:
    BasicSorter(int start);
    vector<char> sort(vector<char> shelf, int mode);
    vector<char> replace(int i, vector<char> shelf);
    int check(vector<char> shelf, char target, int position);

    int getCounter() const;

    void setCounter(int counter);

};


#endif //AALSORTER_BASICSORTER_H
