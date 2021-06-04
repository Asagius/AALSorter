#include "Generator.h"
#include <iostream>
#include <vector>

using namespace std;

Generator:: Generator(int size)
{
    this->size = size;
}

void Generator:: setShelf(int size) {

    shelf.clear();
    this->size = size;

    for (int i = 0; i < size; i++) {
        int tmp = rand() % 4;
        addChar(tmp);
    }
}

void Generator:: addChar(int tmp)
{
    if (tmp == 0 || tmp ==4)
        shelf.push_back('C');
    else if (tmp == 1 || tmp == 5)
        shelf.push_back('M');
    else if (tmp == 2 || tmp == 6)
        shelf.push_back('Y');
    else if (tmp == 3 || tmp == 7)
        shelf.push_back('K');
}

const vector <char> &Generator:: getShelf() const
{
    return shelf;
}

void Generator:: printShelf()
{
    for (int i = 0; i < shelf.size(); i++)
    {
        cout<<shelf[i]<<" ";
    }
    cout<<" "<< endl;
}