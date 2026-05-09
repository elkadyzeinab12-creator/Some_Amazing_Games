#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"
#define PURPLE "\033[35m"
#define MAGENTAd "\033[35m"
#define CYAN   "\033[36m"
#define RED    "\033[1;31m"
#define RESET  "\033[0m"
using namespace std;

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
        cout <<"\n";
        if (i != 3)
            cout << "----------------\n " ;

    }



}
void selection(char &p,char &e,string player3,string player4) {
    while (true) {
        cout << ":::::::::::::::::\n";
        cout << "select X,x or O,o \n ";
        cout << ":::::::::::::::::\n";
        cout << player3 << ":\n";
        cin >> p;
        cout << player4 << ":\n";
        cin >> e;

        if (!((p == 'X' || p == 'O' || p == 'x' || p == 'o') && (e == 'X' || e == 'O' || e == 'x' || e == 'o'))) {
            cout<<RED<< "wrong input!\n"<<RESET;
            cout<<RED<<"please try again.\n"<<RESET;
            cout << "===============================\n";
        }
        else if (tolower(p) ==tolower(e)) {
            cout<<RED<< "the players can't choose the same symbols.\n"<<RESET;
            cout<<RED<< "please try again.\n"<<RESET;
            cout << "===============================\n";
        }
        else {
            p = toupper(p);
            e = toupper(e);

            break;
        }
    }
    cout << "=================================\n";

}


bool checkAccuracy(int &row, int &col, char bgame[4][4])
{
    if (row < 0 || row > 3 || col < 0 || col > 3) {
        cout<<RED<< "Outside the game area!\n"<<RESET;
        return false;
    }

    if (bgame[row][col] != '-') {
        cout<<RED<< "This position is already occupied.\n"<<RESET;
        return false;
    }

    return true;
}



void rowcol(int &row, int &col, string player,char bgame[4][4]) {
    while (true) {
        cout << player << " Enter row and column numbers : \n";
        cout << "_________________________________________\n";
        cout << "Enter row number: \n";
        cin >> row;
        cout << "Enter column number: \n";
        cin >> col;
        if (!checkAccuracy(row, col, bgame)) {
            cout<<RED<< "please try again.\n"<<RESET;
            cout << "=================================\n";
        }
        else
            break;
    }
}


void printBoard(char bgame[4][4]) {
    cout << "-----------------\n";

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

                 cout<<"| ";
            if (bgame[i][j]== 'X')
                cout << CYAN << 'X' << RESET << " ";

            else if (bgame[i][j] == 'O')
                cout << PURPLE << 'O' << RESET << " ";

            else
                cout << bgame[i][j] << " ";
        }

        cout << "|\n";
        cout << "-----------------\n";
    }
}




bool checkWin(char player ,char bgame[4][4]) {
    for(int i = 0 ; i < 4 ; i++) {
        if(bgame[i][0] == player &&
            bgame[i][1] == player &&
            bgame[i][2] == player &&
            bgame[i][3] == player)
            return true;
    }
    for(int j = 0 ; j < 4 ; j++) {
        if(bgame[0][j] == player &&
            bgame[1][j] == player &&
            bgame[2][j] == player &&
            bgame[3][j] == player)
            return true;
    }
    if(bgame[0][0] == player &&
        bgame[1][1] == player &&
        bgame[2][2] == player &&
        bgame[3][3] == player)
        return true;

    if(bgame[0][3] == player &&
      bgame[1][2] == player &&
      bgame[2][1] == player &&
      bgame[3][0] == player)
        return true;
    return false;
}

bool checkDraw(char bgame[4][4]) {
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
            if (bgame[i][j] == '-')
                return false;
        }
    }
    return true;
}


bool winlosdraw(string player3,string player4,char bgame[4][4],char p) {
    if (checkWin(p,bgame)) {
        cout<<"++++++++++++++++++++++++++++++++++++++++\n";
        cout<<MAGENTAd<<"          "<< player4<<" "<< "is the winner\n"<<RESET;
        cout<<"++++++++++++++++++++++++++++++++++++++++\n";
        cout<<RED<<"Good try,"<<player3<<"! You lost this round.\n"<<RESET;

        return false;
    }
    if (checkDraw(bgame)) {
        cout<<RED<< "it's draw! there is no winner."<<RESET;
        return false;
    }
    return true;
}




    void GameOver() {

        cout << "Enter the name of player 1: \n";
        string player1;
        cin >> player1;
        cout << "Enter the name of player 2: \n";
        string player2;
        cin >> player2;
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "Welcome " <<" "<<player1<<" "<< " and "<<" "<< player2<<" "<< " to the BROAD GAME\n";
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "========================================================================================================================\n";
        cout << "The rules of the game are simple:\n";
        cout << "1. The game is played on a 4x4 grid.\n";
        cout << "2. Each player takes turns to place their symbol (X or O) on the grid.\n";
        cout << "3. The first player to get 4 of their symbols in a row as follows:\n "<<
             "(horizontally, vertically, or diagonally) wins the game.\n";
        cout << "4. If all the cells are filled and no player has 4 in a row, the game is a draw.\n";
        cout << "Let's start the game!\n";
        cout << "========================================================================================================================\n";
        cout << ":::::::::::::\n";
        cout << "BOARD GAME\n";
        cout << ":::::::::::::\n";

    char boardgame[4][4];
initializeBoard(boardgame);

        char y, d;
        selection(y,d,player1,player2);


        while (true) {

            int row1, col1;
    rowcol(row1,col1,player1,boardgame);
            boardgame[row1][col1] = y;



                     printBoard(boardgame);
            if (!winlosdraw(player2, player1, boardgame, y))
                break;


            int row2, col2;
            rowcol(row2,col2,player2,boardgame);
            boardgame[row2][col2] = d;



            printBoard(boardgame);
            if (!winlosdraw(player1, player2, boardgame, d))
                break;
        }

    }
