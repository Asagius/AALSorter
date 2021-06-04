#ifndef AALSORTER_GENERATOR_H
#define AALSORTER_GENERATOR_H

#include <vector>
using namespace std;

class Generator {
private:
    vector <char> shelf;
    int size;

public:
    Generator(int size);
    void printShelf();
    void addChar(int colour);
    const vector <char> &getShelf() const;
    vector<char> getFour(int beginning);
    void setShelf(int size);
};


#endif //AALSORTER_GENERATOR_H
