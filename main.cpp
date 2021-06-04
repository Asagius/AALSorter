#include <iostream>
#include "Input.h"
#include "BasicSorter.h"
#include "ImprovedSorter.h"
#include "Tester.h"
#include "Generator.h"

using namespace std;

int main() {


    //Input input;
    //input.read();
    Generator generator(120);

    vector<char> temp1;
    vector<char> temp2;
    vector<char> temp3;

    generator.setShelf(50);
    temp1=generator.getShelf();
    //temp1 = input.getShelf();

    for (int i = 0; i < temp1.size(); ++i) {
        temp2.push_back(temp1[i]);
        temp3.push_back(temp1[i]);
    }

    BasicSorter bs(0);
    ImprovedSorter is(0);
    //bs.sort(temp1);
    is.sort(temp2);
    return 0;
    Tester tester;
    //tester.tests(10, 50, 0);
    //tester.results();
}