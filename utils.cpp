#include "utils.h"
#include"Connect4.h"
#include <bits/stdc++.h>
#include "colors.h"
using namespace std;

char GetSymbol() {
    char currentPlayer;
    while(true) {
        if (!(cin >> currentPlayer)) {
            cin.clear();
            cin.ignore(100,'\n');
        }
        currentPlayer=tolower(currentPlayer);
        if (currentPlayer=='x'||currentPlayer=='o') {
            break;
        }
    }
    return currentPlayer;
}