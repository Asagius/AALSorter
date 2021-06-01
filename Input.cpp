//
// Created by Asagius on 01.06.2021.
//
#include "Input.h"
#include <vector>
#include <iostream>

using namespace std;

vector<char> &Input::getShelf() {
    return shelf;
}

void Input::setShelf(vector<char> &shelf) {
    Input::shelf = shelf;
}

void Input::read() {
    string input_message;
    cout <<"Input sequence of C, M, Y, K" << endl;
    cin >> input_message;

    for (int i = 0; i < input_message.size(); ++i) {
        input.push_back((char)input_message[i]);
    }

    for (int i = 0; i < input_message.size(); i++)
    {
        if (input[i] == 'C' || input[i] == 'M' || input[i] == 'Y' || input[i] == 'K')
            shelf.push_back(input[i]);
    }

    cout <<"Shelf: ";

    for (int i = 0; i < shelf.size(); i++)
        cout<<shelf[i]<<" ";
}
