#include "utils.h"
#include"Connect4.h"
#include <bits/stdc++.h>
#include "colors.h"
using namespace std;

char GetSymbol() {
    char currentPlayer;
    while(true) {
        if (!(cin >> currentPlayer)) {
            cin.clear();
            cin.ignore(100,'\n');
        }
        currentPlayer=tolower(currentPlayer);
        if (currentPlayer=='x'||currentPlayer=='o') {
            break;
        }
    }
    return currentPlayer;
}
int get_int_input(string prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        char extra;

        if (ss >> value && !(ss >> extra)) {
            return value;
        }

        cout << red << "Invalid input, please try Enter a number\n" << RESET;
    }
}