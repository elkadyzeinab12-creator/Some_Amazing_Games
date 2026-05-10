#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

using namespace std;

//initializing board by '-' character
void initializeBoard(char bgame[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bgame[i][j] = '-';
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << bgame[i][j] << " | ";
        }
        cout << "\n";
        if (i != 3)
            cout << "----------------\n ";
    }
}

//the loop of the game starts
void selection(char &p, char &e, string player3, string player4) {
    while (true) {
        cout << ":::::::::::::::::\n";
        cout << "select X or O \n";
        cout << ":::::::::::::::::\n";
        cout << player3 << ":\n";
        cin >> p;
        cout << player4 << ":\n";
        cin >> e;

        if (!((p == 'X' || p == 'O' || p == 'x' || p == 'o') && (e == 'X' || e == 'O' || e == 'x' || e == 'o'))) {
            cout << red << "wrong input!\n" << RESET;
            cout << red << "please try again.\n" << RESET;
            cout << "===============================\n";
        } else if (tolower(p) == tolower(e)) {
            cout << red << "the players can't choose the same symbols.\n" << RESET;
            cout << red << "please try again.\n" << RESET;
            cout << "===============================\n";
        } else {
            p = toupper(p);
            e = toupper(e);

            break;
        }
    }
    cout << "=================================\n";
}

//sara's function to check accuracy and deal with wrong input
bool checkAccuracy(int row, int col, char bgame[4][4]) {
    if (row < 0 || row > 3 || col < 0 || col > 3) {
        cout << red << "Outside the game area!\n" << RESET;
        return false;
    }

    if (bgame[row][col] != '-') {
        cout << red << "This position is already occupied.\n" << RESET;
        return false;
    }

    return true;
}

//rows and columns function to allaws user select the position of the cell
void rowcol(int &row, int &col, string player, char bgame[4][4]) {
    while (true) {
        cout << player << " Enter row and column numbers : \n";
        cout << "_________________________________________\n";
        row=get_int_input("Enter row number: ");
        col=get_int_input("Enter column number: ");

        if (!checkAccuracy(row, col, bgame)) {
            cout << red << "please try again.\n" << RESET;
            cout << "=================================\n";
        } else
            break;
    }
}

//the most sensitive part _printing the nice board_
void printBoard(char bgame[4][4]) {
    cout << "-----------------\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "| ";
            if (bgame[i][j] == 'X')
                cout << cyan << 'X' << RESET << " ";

            else if (bgame[i][j] == 'O')
                cout << LIGHT_PURPLE << 'O' << RESET << " ";

            else
                cout << bgame[i][j] << " ";
        }

        cout << "|\n";
        cout << "-----------------\n";
    }
}

//checking who is the winner
bool checkWin(char player, char bgame[4][4]) {
    for (int i = 0; i < 4; i++) {
        if (bgame[i][0] == player &&
            bgame[i][1] == player &&
            bgame[i][2] == player &&
            bgame[i][3] == player)
            return true;
    }
    for (int j = 0; j < 4; j++) {
        if (bgame[0][j] == player &&
            bgame[1][j] == player &&
            bgame[2][j] == player &&
            bgame[3][j] == player)
            return true;
    }
    if (bgame[0][0] == player &&
        bgame[1][1] == player &&
        bgame[2][2] == player &&
        bgame[3][3] == player)
        return true;

    if (bgame[0][3] == player &&
        bgame[1][2] == player &&
        bgame[2][1] == player &&
        bgame[3][0] == player)
        return true;
    return false;
}

//checking if there is draw
bool checkDraw(char bgame[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bgame[i][j] == '-')
                return false;
        }
    }
    return true;
}

//display the winner
bool winlosdraw(string player3, string player4, char bgame[4][4], char p) {
    if (checkWin(p, bgame)) {
        cout << "++++++++++++++++++++++++++++++++++++++++\n";
        cout << MAGENTAd << "          " << player4 << " " << "is the winner\n" << RESET;
        cout << "++++++++++++++++++++++++++++++++++++++++\n";
        cout << red << "Good try," << player3 << "! You lost this round.\n" << RESET;

        return false;
    }
    if (checkDraw(bgame)) {
        cout << red << "Opps, It's Draw! There Is No Winner." << RESET;
        return false;
    }
    return true;
}

//the main function to run the whole game
void GameOver() {
    cout << "Enter the name of player 1: \n";
    string player1;
    cin >> player1;
    cout << "Enter the name of player 2: \n";
    string player2;
    cin >> player2;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "Welcome " << " " << player1 << " " << " and " << " " << player2 << " " << " to the BROAD GAME\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout <<"========================================================================================================\n";
    cout << "The rules of the game are simple:\n";
    cout << "1. The game is played on a 4x4 grid.\n";
    cout << "2. Each player takes turns to place their symbol (X or O) on the grid.\n";
    cout << "3. The first player to get 4 of their symbols in a row as follows:\n " <<
            "(horizontally, vertically, or diagonally) wins the game.\n";
    cout << "4. If all the cells are filled and no player has 4 in a row, the game is a draw.\n";
    cout << "Let's start the game!\n";
    cout <<
            "=======================================================================================================\n";
    cout << ":::::::::::::\n";
    cout << "BOARD GAME\n";
    cout << ":::::::::::::\n";

    char boardgame[4][4];
    initializeBoard(boardgame);

    char y, d;
    selection(y, d, player1, player2);


    while (true) {
        int row1, col1;
        rowcol(row1, col1, player1, boardgame);
        boardgame[row1][col1] = y;


        printBoard(boardgame);
        if (!winlosdraw(player2, player1, boardgame, y))
            break;


        int row2, col2;
        rowcol(row2, col2, player2, boardgame);
        boardgame[row2][col2] = d;


        printBoard(boardgame);
        if (!winlosdraw(player1, player2, boardgame, d))
            break;
    }
}
