#include "Tester.h"
#include "BasicSorter.h"
#include "ImprovedSorter.h"
#include "Generator.h"
#include <iostream>
#include <chrono>

using namespace std;


//Tester:: Tester(){}

void Tester:: results() {
    cout << "Basic operations:    " << "Improved operations:     " << "Basic time:   " << "Improved time:    " << endl;

    for (int i = 0; i < basicTime.size(); i++) {
        cout.width(20);
        cout << basicOperations[i];
        cout.width(25);
        cout << improvedOperations[i];
        cout.width(15);
        cout << basicTime[i];
        cout.width(18);
        cout << improvedTime[i] << endl;
        //cout.width(20);
        //cout << bfsOperations[i];
        //cout.width(15);
        //cout << bfsTime[i] << endl;
    }
}

void Tester:: tests(int iterations, int size)
{

    BasicSorter bs(0);
    ImprovedSorter is(0);
    //State initialState;
    Generator generator(120);

    vector<char> tab;
    vector<char> tab2;
    vector<char> tab3;

    for(int i = 0; i < iterations; i++)
    {
        generator.setShelf(size);
        tab = generator.getShelf();

        //tab = {'K','Y','M','C','C','M','K','Y','C','M','Y','K','K','K','M','C'};

        for (int i = 0; i< tab.size(); i++)
        {
            tab2.push_back(tab[i]);
        }


        auto t1 = std::chrono::high_resolution_clock::now();
        bs.sort(tab);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        basicTime.push_back(int_ms.count());
        basicOperations.push_back(bs.getCounter());
        bs.setCounter(0);


        t1 = std::chrono::high_resolution_clock::now();
        tab2 = is.sort(tab2);
        bs.sort(tab2);
        t2 = std::chrono::high_resolution_clock::now();
        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        improvedTime.push_back(int_ms.count());
        int counter = is.getCounter() + bs.getCounter();
        improvedOperations.push_back(counter);
        is.setCounter(0);

        

        tab.clear();
        tab2.clear();
        //initialState.colors.clear();
    }
}