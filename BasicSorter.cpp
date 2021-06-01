//
// Created by Asagius on 01.06.2021.
//

#include "BasicSorter.h"
#include <iostream>
#include <vector>

using namespace std;

BasicSorter::BasicSorter(int start) {
    counter = start;
    first = second = third = fourth = 0;
}

int BasicSorter::getCounter() const {
    return counter;
}

void BasicSorter::setCounter(int counter) {
    BasicSorter::counter = counter;
}

int BasicSorter::check(vector<char> shelf, char target, int position) {
    return 0;
}

vector<char> BasicSorter::sort(vector<char> shelf, int mode) {
    return vector<char>();
}

vector<char> BasicSorter::replace(int i, vector<char> shelf) {
    return vector<char>();
}




