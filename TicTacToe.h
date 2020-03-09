#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include <string>
#include <iostream>

using namespace std;
enum status {WIN, DRAW, CONTINUE};

class ticTacToe {
public:
    ticTacToe();

    void play();
    void displayBoard() const;
    bool isValidMove(int row, int column) const;
    void getXOMove(char moveSymbol);
    status gameStatus();
    void restart();


private:
    char board[3][3]{};
    int noOfMoves;
    char playersTurn;
    const char player[2] = {'X', 'O'};
    bool isAvailable[3][3]{};
    status currentStatus = CONTINUE;
};


#endif //TICTACTOE_TICTACTOE_H
