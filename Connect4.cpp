#include "Connect4.h"
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

using namespace std;

void initialVal(char board[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[7][7]) {
    cout << "1 + 2 + 3 + 4 + 5 + 6 + 7" << '\n';
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << board[i][j];
            if (j != 6)cout << " | ";
        }
        if (i != 6)cout << "\n--+---+---+---+---+---+--\n";
    }
}

bool checkRow(char board[7][7], char c, int col) {
    for (int i = 6; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = c;
            return true;
        }
    }
    return false;
}
