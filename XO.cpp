#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

using namespace std;

//initializing board by '-' character
void initializeBoard(char game_board[4][4]) {
    cout << "    0   1   2   3\n";
    cout << YELLOW << "  -----------------\n" << RESET;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game_board[i][j] = '-';
        }
    }


    for (int i = 0; i < 4; i++) {
        cout << RESET << i << " ";
        cout << YELLOW << "| ";
        for (int j = 0; j < 4; j++) {
            cout << RESET << game_board[i][j] << YELLOW << " | ";
        }
        cout << "\n";
        cout << "  -----------------\n";
    }
    cout << "\n";
}

//the loop of the game starts
void selection(char &p, char &e, const  string & player1, const string & player2) {
    while (true) {
        cout << GREEN << ":::::::::::::::::\n" << RESET;
        cout << "select X or O \n";
        cout << GREEN << ":::::::::::::::::\n" << RESET;
        cout << player1 << ":\n";
        cin >> p;
        p = toupper(p);
        cout << player2 << ":\n";
        cin >> e;
        e = toupper(e);

        if (!((p == 'X' || p == 'O') && (e == 'X' || e == 'O'))) {
            cout << red << "wrong input!\n" << RESET;
            cout << red << "please try again.\n" << RESET;
            cout << "===============================\n";
        } else if (p == e) {
            cout << red << "the players can't choose the same symbols.\n" << RESET;
            cout << red << "please try again.\n" << RESET;
            cout << "===============================\n";
        } else
            break;
    }
    cout << "=================================\n";
}

//sara's function to check accuracy and deal with wrong input
bool checkAccuracy(const int &row, const int &col, char game_board[4][4]) {
    if (row < 0 || row > 3 || col < 0 || col > 3) {
        cout << red << "Outside the game area!\n" << RESET;
        return false;
    }

    if (game_board[row][col] != '-') {
        cout << red << "This position is already occupied.\n" << RESET;
        return false;
    }

    return true;
}

//rows and columns function to allows user select the position of the cell
void set_position(int &row, int &col, const string &player, char game_board[4][4]) {
    while (true) {
        cout << GREEN << player << "'s turn!\n" << RESET;
        cout << player << " Enter row and column numbers : \n";
        cout << "_________________________________________\n";
        row = get_int_input("Enter the row number: ");
        col = get_int_input("Enter the column number: ");

        if (!checkAccuracy(row, col, game_board)) {
            cout << red << "please try again.\n" << RESET;
            cout << "=================================\n";
        } else
            break;
    }
}

//the most sensitive part _printing the nice board_
void printBoard(char game_board[4][4]) {
    cout << "    0   1   2   3\n";
    cout << YELLOW << "  -----------------\n" << RESET;

    for (int i = 0; i < 4; i++) {
        cout << i << " ";
        for (int j = 0; j < 4; j++) {
            cout << YELLOW << "| " << RESET;
            if (game_board[i][j] == 'X')
                cout << cyan << 'X' << RESET << " ";

            else if (game_board[i][j] == 'O')
                cout << LIGHT_PURPLE << 'O' << RESET << " ";

            else
                cout << game_board[i][j] << " ";
        }

        cout << YELLOW << "|\n";
        cout << "  -----------------\n" << RESET;
    }
}

//checking who is the winner
bool checkWin(char player, char game_board[4][4]) {
    //Vertical
    for (int i = 0; i < 4; i++) {
        if (game_board[i][0] == player &&
            game_board[i][1] == player &&
            game_board[i][2] == player &&
            game_board[i][3] == player)
            return true;
    }
    //Horizontal
    for (int j = 0; j < 4; j++) {
        if (game_board[0][j] == player &&
            game_board[1][j] == player &&
            game_board[2][j] == player &&
            game_board[3][j] == player)
            return true;
    }
    // \ digonal
    if (game_board[0][0] == player &&
        game_board[1][1] == player &&
        game_board[2][2] == player &&
        game_board[3][3] == player)
        return true;
    // / digonal
    if (game_board[0][3] == player &&
        game_board[1][2] == player &&
        game_board[2][1] == player &&
        game_board[3][0] == player)
        return true;
    return false;
}

//checking if there is draw
bool checkDraw(char game_board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (game_board[i][j] == '-')
                return false;
        }
    }
    return true;
}

//display the winner
bool win_lose_draw(const string &player1,const string & player2, char game_board[4][4], char p) {
    if (checkWin(p, game_board)) {
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << BG << "                    " << player2 << " " << "IS THE WINNER \n" << RESET;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << YELLOW << "Good try," << player1 << "! You lost this round.\n" << RESET;

        return true;
    }
    if (checkDraw(game_board)) {
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << red << "           Opps, It's Draw!\n       "
                "        There Is No Winner.\n" << RESET;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        return true;
    }
    return false;
}

//the main function to run the whole game
void GameOver() {
    cout << "Enter the name of player 1: \n";
    string player1;
    getline(cin, player1);
    cout << "Enter the name of player 2: \n";
    string player2;
    getline(cin, player2);
    cout << GREEN << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
            "Welcome " << " " << player1 << " " << " & " << " " << player2 << " " << " to the BOARD GAME\n"
            "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" << RESET
            "========================================================================================================\n"
            "The rules of the game are simple:\n1. The game is played on a 4x4 grid.\n"
            "2. Each player takes turns to place their symbol (X or O) on the grid.\n"
            "3. The first player to get 4 of their symbols in a row as follows:\n "
            "(horizontally, vertically, or diagonally) wins the game.\n"
            "4. If all the cells are filled and no player has 4 in a row, the game is a draw.\n";
    cout << "Let's start the game!\n"
            "=======================================================================================================\n";
    cout << GREEN << "::::::::::::::::::\n"
            << "BOARD GAME\n::::::::::::::::::\n\n" << RESET;

    char boardgame[4][4];
    initializeBoard(boardgame);
    cout << "\n";
    char y, d;
    selection(y, d, player1, player2);


    while (true) {
        //player1 section

        int row1, col1;
        set_position(row1, col1, player1, boardgame);
        boardgame[row1][col1] = y;


        printBoard(boardgame);
        if (win_lose_draw(player2, player1, boardgame, y))
            break;

        //player2 section

        int row2, col2;
        set_position(row2, col2, player2, boardgame);
        boardgame[row2][col2] = d;


        printBoard(boardgame);
        if (win_lose_draw(player1, player2, boardgame, d))
            break;
    }
}
