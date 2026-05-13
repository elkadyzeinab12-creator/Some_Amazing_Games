#include "Connect4.h"
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

using namespace std;

char board[7][7];

//STRUCT CONTAIN ALL MEMBERS FOR ONE PLAYER
struct player {
    string name = " ";
    char symbol = ' ';
};

//-----------------CLEAR BOARD--------------------------
void initialVal() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
}

//------------------PRINT BOARD-------------------------
void printBoard() {
    cout << " 1 + 2 + 3 + 4 + 5 + 6 + 7" << RESET << '\n';
    for (int i = 0; i < 7; i++) {
        cout << ' ';
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != ' ') {
                cout << (board[i][j] == 'X' ? cyan"X" : PURPLE "O") << RESET;
            } else cout << board[i][j];
            if (j != 6)cout << YELLOW << " | " << RESET;
        }
        if (i != 6)
            cout << YELLOW << "\n---+---+---+---+---+---+---\n" << RESET;
    }
    cout << "\n\n";
}

//--------------------CHECK CELL-------------------------
//WHAT IS THE FIRST EMPTY CELL ?
bool checkCell(char c, int col) {
    for (int i = 6; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = c;
            return true;
        }
    }
    return false;
}

//----------------------CHECK WIN--------------------------
bool CheckWin() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            //Horizontal
            if (board[i][j] != ' ' && j <= 3 &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                return true;
            }
            //Vertical
            if (board[i][j] != ' ' && i <= 3 &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
            //  / digonal
            if (board[i][j] != ' ' && j >= 3 && i <= 3 &&
                board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] &&
                board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
            // \ digonal
            if (board[i][j] != ' ' && j <= 3 && i <= 3 &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

//-----------------------------PLAY GAME---------------------------------
void playGame() {
    int ward = 0;
    player p1, p2;
    cout << YELLOW "\n-------------------< Start Game >-------------------\n" << RESET;
    initialVal();
    // ENTER NAME OF PLAYER
    cout << "Player 1,Please Enter Your Name :";
    getline(cin, p1.name);
    cout << "Player 2,Please Enter Your Name :";
    getline(cin, p2.name);
    //ENTER SYMBOL
    cout << p1.name << " Choose your symbol (X or O): ";
    p1.symbol = GetSymbol();
    p2.symbol = (p1.symbol == 'X' ? 'O' : 'X');

    cout << "    " << p1.name << " ( " << p1.symbol << " ) " <<
            PURPLE << "            VS              " << RESET
            << p2.name << " ( " << p2.symbol << " )\n";

    printBoard();
    player *currentPlayer = &p1;
    while (true) {
        cout << GREEN "Current Player ( " << currentPlayer->name << " ) With Symbol ( " << currentPlayer->symbol <<
                " )\n" << RESET;
        //check valid col
        while (true) {
            int currentCol = get_int_input("Enter Colum (1 - 7):"); //if user enter anything another numbers

            int ColIdx = currentCol - 1;
            if (currentCol > 7 || currentCol < 1) {
                cout << red "Invalid Input , Try Again : \n" << RESET;
            } else if (!checkCell(currentPlayer->symbol, ColIdx)) {
                //check what is the nearest cell is empty in colum
                cout << red "Wrong ! THIS COLUMN IS ALREADY FULL, Try Again :\n" << RESET;
            } else {
                ward++;
                break;
            }
        }
        printBoard();
        if (CheckWin()) {
            cout << "-------------------------------------------------\n";
            cout << "                     GAME OVER                    \n";
            cout << "-------------------------------------------------\n";
            cout << BG "--------------<   PLAYER (" << currentPlayer->name << ") WIN   >--------------\n" << RESET;
            cout << "-------------------------------------------------\n";
            break;
        }
        if (ward == 49) {
            //if we reach to 49 turn and none win that's mean draw
            cout << "-------------------------------------------------\n";
            cout << "                     GAME OVER                    \n";
            cout << "-------------------------------------------------\n";
            cout << red "-------------------<     DRAW     >----------------\n" << RESET;
            cout << "-------------------------------------------------\n";
            break;
        }
        currentPlayer = (currentPlayer->symbol == p1.symbol ? &p2 : &p1); //take turns between user automatically
    }
}

//---------------------------------------FINISH OvO-----------------------------------------------
