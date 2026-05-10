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

void colors_organization() {
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}


void main_menu();//done

void main_loop();//done

void XO();//done

void Connect4();//done


// the main
int main() {
    colors_organization();

    cout << BB << "==========================================================\n";
    cout << "Welcome to Our Amazing Games\n" << RESET;

    main_loop();

    cout <<YELLOW<<"\n--------------------------------------------------------------------------------------------------\n"
        "     < THIS IS THE FIRST VERSION OF THE APPLICATION AND IT WILL BE UPDATED SOON! >        \n"
    "--------------------------------------------------------------------------------------------------\n";

    return 0;
}


void main_menu() {
    cout << BB << "==========================================================\n";
    cout << "Main Menu:\n";
    cout << "1. XO Game\n" // done
    << "2. Connect4 Game\n" // still working on
    << "0. Exit\n";
    cout << "---------------------------------------------\n" << RESET;
}

void XO() {
    int press = -1;
    while (press != 0) {
        GameOver();
        press = get_int_input("Press Any Number Kay To Continue Plying Or Press 0 To Return To The Main Menu... ");
    }
}

void Connect4() {
    int press = -1;
    while (press != 0) {
        char board[7][7];
        playGame(board);
        press = get_int_input("Press Any Number Kay To Continue Plying Or Press 0 To Return To The Main Menu... ");
    }
}

void main_loop() {
    int choice = -1;

    while (choice != 0) {
        main_menu();
        choice = get_int_input("Select A Game To Start The Excitation Or press 0 To Exit: ");
        switch (choice) {
            case 1:
                //xo game
                XO();
                break;
            case 2:
                //Conncet4
                Connect4();
                break;
            case 0:
                break;
            default:
                cout << red << "Invalid Input!\nPlease Enter 1 Or 2 To start Gaming Or Press 0 to terminate\n" << RESET;
                cin.ignore(100, '\n'); //it's a protective way to avoid errors if user enter more than one char or num
        }
    }
    cout << MAGENTAd << "                  WE WISH YOU ENJOYED OUR GAMES!\n     "
                        "                  LET ME SEE YOU AGAIN\n";

}
/*____________________________________< the end >______________________________________*/