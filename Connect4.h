#ifndef SOME_AMAZING_GAMES_CONNECT4_H
#define SOME_AMAZING_GAMES_CONNECT4_H
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

bool check_cell(char arr[7][7],int column, int row);

bool winner(char arr[7][7]);

bool grid(char arr[7][7]);

#endif //SOME_AMAZING_GAMES_CONNECT4_H