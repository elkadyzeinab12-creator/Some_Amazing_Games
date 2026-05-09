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
    cout << '\n';
}

bool checkCell(char board[7][7], char c, int col) {
    for (int i = 6; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = c;
            return true;
        }
    }
    return false;
}

bool CheckWin(char board[7][7]) {
    //horizontal
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j + 1] == board[i][j + 2] &&
                board[i][j + 2] == board[i][j + 3])
                return true;
        }
    }
    //vertical
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j] &&
                board[i + 1][j] == board[i + 2][j] &&
                board[i + 2][j] == board[i + 3][j])
                return true;
        }
    }
    // / digonal

    // \ digonal
    return false;
}

void playGame(char board[7][7]) {
    char currentPlayer, p1, p2;
    int currentCol, ColIdx, turn = 1, ward = 0;
    bool run = true;
    cout << "\n-------------------< Start Game >-------------------\n";
    initialVal(board);
    cout << "Player 1, choose your symbol (X or O): ";
    p1 = GetSymbol();
    p2 = (p1 == 'x' ? 'o' : 'x');
    cout << "Player 1 : ( " << p1 << " )\n" << "Player 2 : ( " << p2 << " )\n";
    printBoard(board);
    while (run) {
        cout << "Enter Symbol :";
        char expectedSymbol = (turn == 1 ? p1 : p2);
        //check valid symbol
        while (true) {
            currentPlayer = GetSymbol();
            if (currentPlayer == expectedSymbol)
                break;
            else
                cout << "Wrong symbol! It's Player " << "Enter (" << expectedSymbol << "): ";
        }
        cout << "Enter Colum (1 - 7):";
        //check valid col
        while (cin >> currentCol) {
            ColIdx = currentCol - 1;
            if (currentCol > 7 || currentCol < 1) {
                cout << "Invalid input , Try again : \n";
            } else if (!checkCell(board, currentPlayer, ColIdx)) {
                cout << "Wrong ! try again :\n";
            } else {
                ward++;
                break;
            }
        }
        printBoard(board);
        if (CheckWin(board)) {
            cout << "-------------------------------------------------\n";
            cout << "                     GAME OVER                    \n";
            cout << "-------------------------------------------------\n";
            cout << "---------<  Player (" << turn << ") win   >--------\n";
            run = false;
        }
        if (ward == 49) {
            cout << "-------------------------------------------------\n";
            cout << "                     GAME OVER                    \n";
            cout << "-------------------------------------------------\n";
            cout << "-------------------<    Draw    >----------------\n";
            run = false;
        }
        turn = (turn == 2 ? 1 : 2);
    }
}
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

bool check(int &row, int &col, char board[7][7])
{
    if (row < 0 || row > 6 || col < 0 || col > 6) {
        cout << "Outside the game area";
        return false;
    }

    if (board[row][col] != ' ') {
        cout << "This position is already occupied";
        return false;
    }

    return true;
}