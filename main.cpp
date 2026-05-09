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


void main_menu();
void main_loop();
void XO();
void Connect4();

int main() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
    cout<<BLUE<<"==========================================================\n";
    cout << "Welcome to Our Amazing Games!\n" << RESET;

    main_loop();

}

void main_menu(){
    cout<<BLUE<<"==========================================================\n";
    cout<<"Main Menu:\n";
    cout<<"1. XO Game\n"<<"2. Connect4 Game\n"<<"0. Exit\n";
    cout<<"---------------------------------------------\n"<<RESET;
    cout<<"Select A Game To Start The Excitation Or press 0 To Exit: ";
}

void XO() {
    int press=-1;
    while(press!=0) {

        cout <<"Press Any Number Kay To Continue Plying Or Press 0 To Return To The Main Menu... ";
        cin >> press;
    }

}

void Connect4() {
    int press=-1;
    while(press!=0) {

        cout <<"Press Any Number Kay To Continue Plying Or Press 0 To Return To The Main Menu... ";
        cin >> press;
    }
}

void main_loop() {
    int choice = -1;
    while (choice != 0) {
        main_menu();
        cin>>choice;
        switch(choice) {
                case 1:
                //xo game
                XO();
                break;
                case 2:
                //connect4 game
                Connect4();
                break;
                case 0:
                break;
                default:
                cout<<red<<"Invalid Input!\nPlease Enter 1 Or 2 To start Gaming Or Press 0 to terminate\n"<<RESET;
        }
    }
    cout<<PURPLE<<"WE WISH YOU ENJOYED OUR GAMES!\n      LET ME SEE YOU AGAIN\n";

}

