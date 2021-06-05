#ifndef AALSORTER_IMPROVEDSORTER_H
#define AALSORTER_IMPROVEDSORTER_H

#include "BasicSorter.h"
#include <vector>

using namespace std;

class ImprovedSorter: public BasicSorter {
private:
    int counter;

public:
    ImprovedSorter(int start);
    vector<char> sort(vector<char> shelf);
    int findFour(vector<char> shelf, char target);
    int getCounter();
    void setCounter(int counter);
};


#endif //AALSORTER_IMPROVEDSORTER_H
