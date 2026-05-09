#ifndef SOME_AMAZING_GAMES_CONNECT4_H
#define SOME_AMAZING_GAMES_CONNECT4_H
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

bool winner(char arr[7][7]);

bool grid(char arr[7][7]);

void initialVal(char board[7][7]);

void printBoard(char board[7][7]);

bool checkCell(char board[7][7], char c, int col);
#endif //SOME_AMAZING_GAMES_CONNECT4_H
