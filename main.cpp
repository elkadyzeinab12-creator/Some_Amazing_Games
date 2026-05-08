#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "utils.h"
#include "colors.h"
#include "Connect4.h"
#include "XO.h"

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
    cout<<BLUE<<"==========================================================\n";
    cout << "Welcome to Our amazing Games!\n" << RESET;
    cout<<BLUE<<"==========================================================\n";
    cout<<"Main Menu:\n";
    cout<<"1. XOR Game\n"<<"2. Connect4 Game\n"<<"0. Exit\n";
    cout<<"---------------------------------------------\n"<<RESET;
    cout<<"Select A Game To Start The Excitation Or press 0 To Exit: ";


}