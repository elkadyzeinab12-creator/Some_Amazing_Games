#include "utils.h"
#include"Connect4.h"
#include <bits/stdc++.h>
#include "colors.h"
using namespace std;

char GetSymbol() {
    char currentPlayer;
    while (true) {
        if (!(cin >> currentPlayer)) {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cin.ignore(100,'\n');//if user enter more than one char to avoid crash
        currentPlayer = tolower(currentPlayer);
        if (currentPlayer == 'x' || currentPlayer == 'o') {
            break;
        }
        cout << red << "Invalid Input ! Please Try Again :\n" << RESET;
    }
    return currentPlayer;
}

int get_int_input(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout<<red<<"Invalid input, please try Enter a number\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
