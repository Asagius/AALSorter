#include "ImprovedSorter.h"
#include <iostream>


using namespace std;

ImprovedSorter::ImprovedSorter(int start) : BasicSorter(start) {
    counter = start;
}

int ImprovedSorter::getCounter() {
    return counter;
}

void ImprovedSorter::setCounter(int counter) {
    ImprovedSorter::counter = counter;
}

/*
 *Finds a four on the shelf, that starts with letter "target".
 *After finding the beginning of a four uses function check() to check the possibility of moving the four.
 *If the searched four does not exist, returns -1
 */
int ImprovedSorter::findFour(vector<char> shelf, char target) {
    int tmp;

    for (int i = 0; i < shelf.size() - 4; i++) {
        if (target == 'C') {
            if (shelf[i] == 'M') {
                tmp = check(shelf, 'M', i);
                if (tmp == 1)
                    return i;
            }
        } else if (target == 'M') {
            if (shelf[i] == 'Y') {
                tmp = check(shelf, 'Y', i);
                if (tmp == 1)
                    return i;
            }
        } else if (target == 'Y') {
            if (shelf[i] == 'K') {
                tmp = check(shelf, 'K', i);
                if (tmp == 1)
                    return i;
            }
        } else if (target == 'K') {
            if (shelf[i] == 'C') {
                tmp = check(shelf, 'C', i);
                if (tmp == 1)
                    return i;
            }
        }
    }
    return -1;
}

vector<char> ImprovedSorter::sort(vector<char> shelf) {
    counter = 0;

    int tmpCounter = 0;
    int j = 0;

    while (true) {
        if (j >= shelf.size() - 5)
            break;
        if (shelf[j] == 'C' && shelf[j + 1] == 'M' && shelf[j + 2] == 'Y' && shelf[j + 3] == 'K') {
            counter++;
            shelf = replace(j, shelf);
            j = j + 4;

            for (int i = 0; i < shelf.size(); i++)
                cout << shelf[i] << " ";

            continue;
        }
        j++;
    }

    int check = 0;

    while (true) {
        check = findFour(shelf, shelf[shelf.size() - 1]);

        if (check < 0)
            break;

        shelf = replace(check, shelf);


        for (int i = 0; i < shelf.size(); i++) {
            cout << shelf[i] << " ";
        }
        cout << "\n";

        counter++;
    }

    cout << "Sort 2 done" << endl;
    for (int j = 0; j < shelf.size(); j++) {
        cout << shelf[j] << " ";        
    }
    cout << " " << endl;
    cout << "\n" << counter << " operations were performed" << endl;
    return shelf;
}