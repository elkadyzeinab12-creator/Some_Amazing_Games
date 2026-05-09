#include "Connect4.h"
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"


using namespace std;

#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"

bool check(int &row, int &col, char board[7][7])
{
    if (row < 0 || row > 6 || col < 0 || col > 6) {
        cout << "Outside the game area";
        return false;
    }

    if (board[row][col] != ' ') {
        cout << "This position is already occupied";
        return false;
    }

    return true;
}