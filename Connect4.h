#ifndef SOME_AMAZING_GAMES_CONNECT4_H
#define SOME_AMAZING_GAMES_CONNECT4_H

bool CheckWin(char arr[7][7]);

void initialVal(char board[7][7]);

void printBoard(char board[7][7]);

bool checkCell(char board[7][7], char c, int col);

void playGame(char board[7][7]);
#endif //SOME_AMAZING_GAMES_CONNECT4_H
