#ifndef SOME_AMAZING_GAMES_XO_H
#define SOME_AMAZING_GAMES_XO_H

void selection(char &p, char &e, std::string player3, std::string player4);
void initializeBoard(char game_board[4][4]);
void printBoard(char game_board[4][4]);
void set_position(int &row, int &col, std::string player, char game_board[4][4]) ;

bool checkWin(char board[4][4] ,char player);
bool checkAccuracy(int row, int col, char game_board[4][4]);
bool checkDraw(char game_board[4][4]);
bool win_lose_draw(std::string player3, std::string player4, char game_board[4][4], char p) ;

void GameOver();

#endif //SOME_AMAZING_GAMES_XO_H