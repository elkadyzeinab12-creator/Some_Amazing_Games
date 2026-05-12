#ifndef SOME_AMAZING_GAMES_XO_H
#define SOME_AMAZING_GAMES_XO_H

void selection(char &p, char &e, const std::string &player1, const std::string &player2);
void initializeBoard(char game_board[4][4]);
void printBoard(char game_board[4][4]);
void set_position(int &row, int &col, const std::string &player, char game_board[4][4]) ;

bool checkWin(char board[4][4] ,char player);
bool checkAccuracy(const int &row, const int &col, char game_board[4][4]);
bool checkDraw(char game_board[4][4]);
bool win_lose_draw(const std::string &player1, const std::string &player2, char game_board[4][4], char p) ;

void GameOver();

#endif //SOME_AMAZING_GAMES_XO_H