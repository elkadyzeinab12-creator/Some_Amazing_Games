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

int get_int_input(const string &prompt) {
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
    }
}

void showWinMessage(const string &playerName) {
    string message = "  CONGRATULATIONS! PLAYER (" + playerName + ") WINS!  ";
    int n = message.length();

    cout << "\t\t ";
    for (int i = 0; i < n; i++) cout <<BLUE "*";

    cout << "\n\t\t "<<BG << message <<RESET " ";

    cout << "\n\t\t ";
    for (int i = 0; i < n; i++) cout << BLUE"*"<<RESET;
    cout<<"\n";
}

// int value;
// string line;
// while (true) {
//     cout << prompt;
//     getline(cin, line);
//     stringstream ss(line);
//     char extra;
//
//     if (ss >> value && !(ss >> extra)) {
//         return value;
//     }
//
//     cout << red << "Invalid input, please try Enter a number\n" << RESET;
// }