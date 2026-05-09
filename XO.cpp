#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"
using namespace std;


bool chckWin(char board[4][4] ,char player) {
    for(int i = 0 ; i < 4 ; i++) {
        if(board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player &&
            board[i][3] == player)
            return true;
    }
    for(int j = 0 ; j < 4 ; j++) {
        if(board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player &&
            board[3][j] == player)
            return true;
    }
    if(board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player &&
        board[3][3] == player)
        return true;

    if(board[0][3] == player &&
      board[1][2] == player &&
      board[2][1] == player &&
      board[3][0] == player)
        return true;
    return false;
}

bool checkDraw(char board[4][4]) {
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
            if (board[i][j] == '-')
                return false;
        }
    }
    return true;
}

void game() {
    char boardgame[4][4];
	cout << "Enter the name of player 1: \n";
	string player1;
	cin >> player1;
	cout << "Enter the name of player 2: \n";
	string player2;
	cin >> player2;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout << "Welcome " << player1 << " and " << player2 << " to the BROAD GAME\n";
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "========================================================================================================================\n";
    cout << "The rules of the game are simple:\n";
	cout << "1. The game is played on a 4x4 grid.\n";
	cout << "2. Each player takes turns to place their symbol (X or O) on the grid.\n";
	cout << "3. The first player to get 4 of their symbols in a row (horizontally, vertically, or diagonally) wins the game.\n";
	cout << "4. If all the cells are filled and no player has 4 in a row, the game is a draw.\n";
	cout << "Let's start the game!\n";
    cout << "========================================================================================================================\n";
    cout << ":::::::::::::\n";
    cout << "BROAD GAME\n";
	cout << ":::::::::::::\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardgame[i][j] = '-';
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << boardgame[i][j] << " | ";
        }
        cout << endl;
        if (i != 3)
            cout << "----------------" << endl;

    }
    char y, d;
    while (true) {
        cout << ":::::::::::::::::\n";
        cout << "select X,x or O,o \n ";
        cout << ":::::::::::::::::\n";
        cout << player1 << ":\n";
        cin >> y;
        cout << player2 << ":\n";
        cin >> d;

        if (!((y == 'X' || y == 'O' || y == 'x' || y == 'o') && (d == 'X' || d == 'O' || d == 'x' || d == 'o'))) {
            cout << "wrong input";
            cout << "please try again\n";
            cout << "===============================\n";
        }
        else if (tolower(y) ==tolower(d)) {
            cout << "the players can't choose the same symbols\n";
            cout << "please try again\n";
            cout << "===============================\n";
        }
        else
            break;
    }
        cout << "=================================";

         while(true) {
            int row1, col1;
            while (true) {
                cout << player1 << " Enter row and column numbers : \n";
                cout << "_________________________________________\n";
                cout << "Enter row number: ";
                cin >> row1;
                cout << "Enter column number: ";
                cin >> col1;
                if (!check(row1, col1, boardgame)) {
                    cout << "please try again!\n";
                    cout << "=================================\n";
                }
                else
                    break;
            }
            boardgame[row1][col1] = y;

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == row1 && j == col1) {
                        boardgame[i][j] = y;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << boardgame[i][j] << " ";
                }
                cout << endl;
            }
            if (bool checkwin(boardgame, player1) == 1) {
                cout << player1 << "is the winner";
                break;
            }
            else if (bool checkDraw( boardgame)==1) {
                cout << "it's draw!";
                break;
            }

            int row2, col2;
            while (true) {
                cout << player2 << " Enter row and column numbers : \n";
                cout << "_________________________________________\n";
                cout << "Enter row number: ";
                cin >> row2;
                cout << "Enter column number: ";
                cin >> col2;
                if (!check(row2, col2, boardgame)) {
                    cout << "please try again!\n";
                    cout << "=================================\n";
                }
                else
                    break;
            }
            boardgame[row2][col2] = d;

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == row2 && j == col2) {
                        boardgame[i][j] = d;
                    }
                    if (i == row1 && j == col1) {
                        boardgame[i][j] = y;
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << boardgame[i][j] << " ";
                }
                cout << endl;
            }

            if (bool checkwin(boardgame, player2) == 1) {
                cout << player2 << "is the winner";
                break;
            }
            else if (bool checkDraw(boardgame)==1) {
                cout << "it's draw!";
                break;
            }

        }

}