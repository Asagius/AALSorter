#include <iostream>
#include "Input.h"
#include <vector>
#include "BasicSorter.h"

using namespace std;

int main() {
    int iterating_mode, iterations, size, step;

    Input input;
    input.read();

    vector<char>temp1;
    vector<char>temp2;
    vector<char>temp3;

    temp1=input.getShelf();

    for (int i = 0; i < temp1.size(); ++i) {
        temp2.push_back(temp1[i]);
        temp3.push_back(temp1[i]);
    }

    BasicSorter bs(0);
    bs.sort(temp1, 0);
    return 0;
}