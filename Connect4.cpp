#include "Connect4.h"
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"


using namespace std;

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
                cout << (board[i][j] == 'x' ? LIGHT_YELLOW"X" : PURPLE "O") << RESET;
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
                board[i][j] == board[i][j + 3])
                return true;
        }
    }
    //vertical
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j])
                return true;
        }
    }
    // \ digonal
    for (int k = 3; k <= 9; k++) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (i + j == k) {
                    int ptr = k - 3;
                    for (int l = k - 1; l >= 0; l--) {
                        if (board[k][ptr] == board[l][ptr + 1] &&
                            board[k][ptr] == board[l - 1][ptr + 2] &&
                            board[k][ptr] == board[l - 2][ptr + 3] &&
                            board[k][ptr] != ' ')
                            return true;
                        if (l - 2 <= 0 || ptr + 3 >= 9)
                            break;
                        ptr++;
                    }
                }
            }
        }
    }

    // / digonal
    for (int k = 0; k <= 3; k++) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (abs(i - j) == k) {
                    int g = max(i, j), s = min(i, j);

                    if (board[g][s] != ' ' &&
                        board[g][s] == board[g + 1][s + 1] &&
                        board[g][s] == board[g + 2][s + 2] &&
                        board[g][s] == board[g + 3][s + 3])
                        return true;
                    if (board[s][g] != ' ' &&
                        board[s][g] == board[s + 1][g + 1] &&
                        board[s][g] == board[s + 2][g + 2] &&
                        board[s][g] == board[s + 3][g + 3])
                        return true;
                }
            }
        }
    }

    return false;
}

//-----------------------------PLAY GAME---------------------------------
void playGame(char board[7][7]) {
    char currentPlayer, p1, p2;
    int currentCol, ColIdx, ward = 0;
    cout << YELLOW "\n-------------------< Start Game >-------------------\n" << RESET;
    initialVal(board);
    cout << "Player 1, choose your symbol (X or O): ";
    p1 = GetSymbol();
    p2 = (p1 == 'x' ? 'o' : 'x');
    cout << "Player 1 : ( " << p1 << " )            " << "Player 2 : ( " << p2 << " )\n";
    printBoard(board);
    currentPlayer = p1;
    while (true) {
        cout << "Current Player ( " << currentPlayer << " )\n";
        cout << "Enter Colum (1 - 7):";
        //check valid col
        while (true) {
            if (!(cin >> currentCol)) {
                //if user enter anything another numbers
                cin.clear();
                cin.ignore(100, '\n');
                cout << red "Invalid input , Try again : \n" << RESET;
                continue;
            }
            cin.ignore(100, '\n'); //it's a protective way to avoid errors if user enter more than one char or num
            ColIdx = currentCol - 1;
            if (currentCol > 7 || currentCol < 1) {
                cout << red "Invalid input , Try again : \n" << RESET;
            } else if (!checkCell(board, currentPlayer, ColIdx)) {
                //check what is the nearest cell is empty in colum
                cout << red "Wrong ! try again :\n" << RESET;
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
            cout << BG "--------------<  Player (" << currentPlayer << ") win   >--------------\n" << RESET;
            cout << "-------------------------------------------------\n";
            break;
        }
        if (ward == 49) {
            //if we reach to 49 turn and none win that's mean draw
            cout << "-------------------------------------------------\n";
            cout << "                     GAME OVER                    \n";
            cout << "-------------------------------------------------\n";
            cout << red "-------------------<    Draw    >----------------\n" << RESET;
            cout << "-------------------------------------------------\n";
            break;
        }
        currentPlayer = (currentPlayer == p1 ? p2 : p1); //take turns between user automatically
    }
}

//---------------------------------------FINISH OvO-----------------------------------------------
