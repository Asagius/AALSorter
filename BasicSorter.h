#ifndef AALSORTER_BASICSORTER_H
#define AALSORTER_BASICSORTER_H


#include <vector>
using namespace std;

class BasicSorter {
private:
    int counter;

public:
    BasicSorter(int start);
    int check(vector<char> shelf, char target, int position);
    vector<char> sort(vector<char> shelf);
    vector<char> replace(int i, vector<char> shelf);


    int getCounter() const;
    void setCounter(int counter);

};


#endif //AALSORTER_BASICSORTER_H
