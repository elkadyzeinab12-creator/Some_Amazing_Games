#include "Connect4.h"
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"


using namespace std;

//STRUCT CONTAIN ALL MEMBERS FOR ONE PLAYER
struct player {
    string name =" " ;
    char symbol=' ';
    int ward = 0;
};

//-----------------CLEAR BOARD--------------------------
void initialVal(char board[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
}

//------------------PRINT BOARD-------------------------
void printBoard(char board[7][7]) {
    cout << " 1 + 2 + 3 + 4 + 5 + 6 + 7" << '\n';
    for (int i = 0; i < 7; i++) {
        cout << ' ';
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != ' ') {
                cout << (board[i][j] == 'X' ? LIGHT_YELLOW"X" : PURPLE "O") << RESET;
            } else cout << board[i][j];
            if (j != 6)cout << " | ";
        }
        if (i != 6)
            cout << "\n---+---+---+---+---+---+---\n" << RESET;
    }
    cout << '\n';
}

//--------------------CHECK CELL-------------------------
//WHAT IS THE FIRST EMPTY CELL ?
bool checkCell(char board[7][7], char c, int col) {
    for (int i = 6; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = c;
            return true;
        }
    }
    return false;
}

//----------------------CHECK WIN--------------------------
bool CheckWin(char board[7][7]) {
    //horizontal
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                cout<<"horizontal\n";
                return true;
            }
        }
    }
    //vertical
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                cout<<"vertical\n";
                return true;
            }
        }
    }
    //  / digonal
    for (int k = 3; k <= 9; k++) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (i + j == k) {
                    int g = max(i, j), s = min(i, j);//i=4 j=5

                    if (board[g][s] == board[g - 1][s + 1] &&
                        board[g][s] == board[g - 2][s + 2] &&
                        board[g][s] == board[g - 3][s + 3] &&
                        board[g][s] != ' ') {
                        cout<<"diagonal/\n";
                        return true;
                    }
                    if (board[s][g] != ' ' &&
                        board[s][g] == board[s + 1][g - 1] &&
                        board[s][g] == board[s + 2][g - 2] &&
                        board[s][g] == board[s + 3][g - 3]) {
                        cout<<"diagonal/\n";
                        return true;
                    }
                }
            }
        }
    }

    // \ digonal
    for (int k = 0; k <= 3; k++) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (abs(i - j) == k) {
                    int g = max(i, j), s = min(i, j);//I=4 J=4

                    if (board[g][s] != ' ' &&
                        board[g][s] == board[g + 1][s + 1] &&
                        board[g][s] == board[g + 2][s + 2] &&
                        board[g][s] == board[g + 3][s + 3]) {
                        cout<<"diagonal\\\n";
                        return true;
                    }
                    if (board[s][g] != ' ' &&
                        board[s][g] == board[s + 1][g + 1] &&
                        board[s][g] == board[s + 2][g + 2] &&
                        board[s][g] == board[s + 3][g + 3]) {
                        cout<<"diagonal\\\n";
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

//-----------------------------PLAY GAME---------------------------------
void playGame(char board[7][7]) {
    player p1, p2;
    cout << YELLOW "\n-------------------< Start Game >-------------------\n" << RESET;
    initialVal(board);
    // ENTER NAME OF PLAYER
    cout << "Player 1,Please Enter Your Name :";
    getline(cin , p1.name);
    cout << "Player 2,Please Enter Your Name :";
    getline(cin , p2.name);
    //ENTER SYMBOL
    cout << p1.name <<" Choose your symbol (X or O): ";
    p1.symbol = GetSymbol();
    p2.symbol = (p1.symbol == 'X' ? 'O' : 'X');
    cout << p1.name << " ( " << p1.symbol << " )            " << p2.name << " ( " << p2.symbol << " )\n\n";

    printBoard(board);
    player *currentPlayer = &p1;
    while (true) {
        cout << GREEN "Current Player ( " << currentPlayer->name << " ) With Symbol ( "<<currentPlayer->symbol <<" )\n"<<RESET;
        //check valid col
        while (true) {
            int currentCol=get_int_input("Enter Colum (1 - 7):");  //if user enter anything another numbers

            int ColIdx = currentCol - 1;
            if (currentCol > 7 || currentCol < 1) {
                cout << red "Invalid Input , Try Again : \n" << RESET;
            } else if (!checkCell(board, currentPlayer->symbol, ColIdx)) {
                //check what is the nearest cell is empty in colum
                cout << red "Wrong ! THIS COLUMN IS ALREADY FULL, Try Again :\n" << RESET;
            } else {
                currentPlayer->ward++;
                break;
            }
        }
        printBoard(board);
        if (CheckWin(board)) {
            cout << "-------------------------------------------------\n";
            cout << "                     GAME OVER                    \n";
            cout << "-------------------------------------------------\n";
            cout << BG "--------------<   PLAYER (" << currentPlayer->name << ") WIN   >--------------\n" << RESET;
            cout << "-------------------------------------------------\n";
            break;
        }
        if (currentPlayer->ward == 49) {
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
