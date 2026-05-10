#include "utils.h"
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
        currentPlayer = toupper(currentPlayer);
        if (currentPlayer == 'X' || currentPlayer == 'O') {
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
        if (cin >> value) {
            cin.ignore(100, '\n'); //it's a protective way to avoid errors if user enter more than one char or num
            return value;
        }
        cout<<red<<"Invalid Input, Please Try Enter An Integer Number\n"<<RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(100, '\n'); //it's a protective way to avoid errors if user enter more than one char or num
    }
}