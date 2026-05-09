#include <bits/stdc++.h>
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
