#ifndef AALSORTER_INPUT_H
#define AALSORTER_INPUT_H

#include <vector>

using namespace std;

class Input{
private:
    vector<char> shelf;
    vector<char> input;
public:
    void read();
    vector<char> &getShelf();
    void setShelf(vector<char> &shelf);
};

#endif //AALSORTER_INPUT_H