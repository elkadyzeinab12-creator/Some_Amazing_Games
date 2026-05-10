#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

using namespace std;

//initializing board by '-' character
void initializeBoard(char game_board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game_board[i][j] = '-';
        }
    }
cout<<YELLOW"| ";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout <<RESET<< game_board[i][j] <<YELLOW " | ";
        }
        cout << "\n";
        if (i != 3)
            cout << "-----------------\n| ";
    }
}

//the loop of the game starts
void selection(char &p, char &e, string player3, string player4) {
    while (true) {
        cout << GREEN":::::::::::::::::\n"<<RESET;
        cout << "select X or O \n";
        cout <<GREEN ":::::::::::::::::\n"<<RESET;
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
bool checkAccuracy(int row, int col, char game_board[4][4]) {
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
void set_position(int &row, int &col, string player, char game_board[4][4]) {
    while (true) {
        cout << player << " Enter row and column numbers : \n";
        cout << "_________________________________________\n";
        row=get_int_input("Enter row number: ");
        col=get_int_input("Enter column number: ");

        if (!checkAccuracy(row, col, game_board)) {
            cout << red << "please try again.\n" << RESET;
            cout << "=================================\n";
        } else
            break;
    }
}

//the most sensitive part _printing the nice board_
void printBoard(char game_board[4][4]) {
    cout <<YELLOW "-----------------\n"<<RESET;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout <<YELLOW "| "<<RESET;
            if (game_board[i][j] == 'X')
                cout << cyan << 'X' << RESET << " ";

            else if (game_board[i][j] == 'O')
                cout << LIGHT_PURPLE << 'O' << RESET << " ";

            else
                cout << game_board[i][j] << " ";
        }

        cout << YELLOW"|\n";
        cout << "-----------------\n"<<RESET;
    }
}

//checking who is the winner
bool checkWin(char player, char game_board[4][4]) {
    for (int i = 0; i < 4; i++) {
        if (game_board[i][0] == player &&
            game_board[i][1] == player &&
            game_board[i][2] == player &&
            game_board[i][3] == player)
            return true;
    }
    for (int j = 0; j < 4; j++) {
        if (game_board[0][j] == player &&
            game_board[1][j] == player &&
            game_board[2][j] == player &&
            game_board[3][j] == player)
            return true;
    }
    if (game_board[0][0] == player &&
        game_board[1][1] == player &&
        game_board[2][2] == player &&
        game_board[3][3] == player)
        return true;

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
bool win_lose_draw(string player3, string player4, char game_board[4][4], char p) {
    if (checkWin(p, game_board)) {
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << BG << "            " << player4 << " " << "IS THE WINNER \n" << RESET;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << YELLOW << "Good try," << player3 << "! You lost this round.\n" << RESET;

        return false;
    }
    if (checkDraw(game_board)) {
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
    cout <<GREEN "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "Welcome " << " " << player1 << " " << " and " << " " << player2 << " " << " to the BROAD GAME\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"<<RESET;
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
    cout <<GREEN "::::::::::::::::::\n";
    cout << "BOARD GAME\n";
    cout << "::::::::::::::::::\n"<<RESET;

    char boardgame[4][4];
    initializeBoard(boardgame);

    char y, d;
    selection(y, d, player1, player2);


    while (true) {
        int row1, col1;
        set_position(row1, col1, player1, boardgame);
        boardgame[row1][col1] = y;


        printBoard(boardgame);
        if (!win_lose_draw(player2, player1, boardgame, y))
            break;


        int row2, col2;
        set_position(row2, col2, player2, boardgame);
        boardgame[row2][col2] = d;


        printBoard(boardgame);
        if (!win_lose_draw(player1, player2, boardgame, d))
            break;
    }
}
