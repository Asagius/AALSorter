#include "BasicSorter.h"
#include <iostream>


using namespace std;

BasicSorter::BasicSorter(int start) {
    counter = start;
}

int BasicSorter::getCounter() const {
    return counter;
}

void BasicSorter::setCounter(int counter) {
    BasicSorter::counter = counter;
}


/*
 *Move selected 4 colors to the end of the shelf
 *Arguments: shelf, position of the first element of four
 */

vector<char> BasicSorter::replace(int i, vector<char> shelf) {

    counter++;
    vector<char> move;

    move.push_back(shelf[i]);
    move.push_back(shelf[i + 1]);
    move.push_back(shelf[i + 2]);
    move.push_back(shelf[i + 3]);

    vector<char>::iterator it = shelf.begin();
    it = it + i;

    shelf.erase(it, it + 4);
    shelf.push_back(move[0]);
    shelf.push_back(move[1]);
    shelf.push_back(move[2]);
    shelf.push_back(move[3]);

    return shelf;
}

vector<char> BasicSorter::sort(vector<char> shelf) {

    int tmpCounter = 0;

    int i = 0;

    while (1) {
        for (int i = 0; i < shelf.size(); i++) {
            cout << shelf[i] << " ";
        }
        cout << " " << endl;

        tmpCounter++;
        //cout << (shelf.size()-i)*4 << endl;
        if (tmpCounter == (shelf.size()-i)*4)
            break;

        if (i >= shelf.size())
            break;

        if (shelf[i] != 'C') {
            shelf = replace(i, shelf);
            continue;
        }

        if (shelf[i + 1] != 'M') {
            shelf = replace(i + 1, shelf);
            continue;
        }

        if (shelf[i + 2] != 'Y') {
            shelf = replace(i + 2, shelf);
            continue;
        }

        if (shelf[i + 3] != 'K') {
            shelf = replace(i + 3, shelf);
            continue;
        }

        i = i + 4;
        tmpCounter = 0;

        cout << "\nSort 1 done" << endl;
        for (int j = 0; j < shelf.size(); j++) {
            cout << shelf[j] << " ";

        }
        cout << "\n" << counter << " operations were performed" << endl;
    }
    return shelf;
}

/*
 *Checks if it is possible to move a four without breaking correct sequence
 *Arguments: shelf, beginning of the four and the first element of four
 */

int BasicSorter::check(vector<char> shelf, char target, int position) {
    if (position != 0) {
        if (target == 'C') {
            if (shelf[position - 1] == 'K')
                return 0;
        } else if (target == 'M') {
            if (shelf[position - 1] == 'C')
                return 0;
        } else if (target == 'Y') {
            if (shelf[position - 1] == 'M')
                return 0;
        } else if (target == 'K') {
            if (shelf[position - 1] == 'Y')
                return 0;
        }
    }

    if (position < shelf.size() - 5) {
        if (shelf[position + 3] == 'K' && shelf[position + 4] == 'C')
            return 0;
        else if (shelf[position + 3] == 'C' && shelf[position + 4] == 'M')
            return 0;
        else if (shelf[position + 3] == 'M' && shelf[position + 4] == 'Y')
            return 0;
        else if (shelf[position + 3] == 'Y' && shelf[position + 4] == 'K')
            return 0;
    }
    return 1;
}
