//
// Created by Jaquan Jones on 3/1/20.
//

#include "TicTacToe.h"

ticTacToe::ticTacToe() {
    noOfMoves = 0;
    playersTurn = player[0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
            isAvailable[i][j] = true;
        }
    }
}

void ticTacToe::play() {
    cout << "\n\t\tN E W\tG A M E\n";
    displayBoard();

    while (currentStatus == CONTINUE) {
        getXOMove(playersTurn);
    }

    if (currentStatus == DRAW || currentStatus == WIN) {
        restart();
    }
}


void ticTacToe::displayBoard() const {

    cout << "-------------------------------\n\n";
    cout << "\t1\t\t2\t\t3\n";
    cout << "1\t" << board[0][0] << "\t|\t" << board[0][1] << "\t|\t" << board[0][2] << "\n";
    cout << " -------------------------\n";
    cout << "2\t" << board[1][0] << "\t|\t" << board[1][1] << "\t|\t" << board[1][2] << "\n";
    cout << " -------------------------\n";
    cout << "3\t" << board[2][0] << "\t|\t" << board[2][1] << "\t|\t" << board[2][2] << "\n\n";

}

bool ticTacToe::isValidMove(int _row, int _column) const {
    if (isAvailable[_row][_column]) {
        return true;
    } else {
        cout << "\nInvalid Move!\n";
        return false;
    }
}

void ticTacToe::getXOMove(char players_turn) {
    int row, column;

    if (currentStatus == CONTINUE) {
        do {
            if (players_turn == 'X') {
                cout << "X, your turn!\n";
            }
            if (players_turn == 'O') {
                cout << "O, your turn!\n";
            }

            cout << "Enter row for move: \n";
            cin >> row;
            row--;

            cout << "Enter Column for move: \n";
            cin >> column;
            column--;
        } while (!isValidMove(row, column));

        if (isValidMove(row, column)) {
            board[row][column] = players_turn;
            noOfMoves++;
            isAvailable[row][column] = false;
            gameStatus();
            displayBoard();

            if (currentStatus == CONTINUE) {
                if (players_turn == player[0]) {
                    players_turn = player[1];
                    getXOMove(players_turn);
                }

                if (players_turn == player[1]) {
                    players_turn = player[0];
                    getXOMove(players_turn);
                }
            }
        }
    } else {
        restart();
    }
}

status ticTacToe::gameStatus() {
    char winner = ' ';

    for (int i = 0; i < 3; i++) {
        // check for horizontal wins
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') ||
            (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')) {
            winner = board[i][0];
            currentStatus = WIN;
        }

        // check for vertical wins
        if ((board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') ||
            (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')) {
            winner = board[0][i];
            currentStatus = WIN;
        }
    }

    // check for diagonal wins
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')) {
        winner = board[0][0];
        currentStatus = WIN;
    }

    if ((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') ||
        (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
        winner = board[0][2];
        currentStatus = WIN;
    }

    if (noOfMoves >= 8) {
        cout << "Uh-Oh, this match was a draw!\n";
        currentStatus = DRAW;
    }

    if (currentStatus == WIN) {
        cout << "\n" << winner << " is winner!\n";
    }

    return currentStatus;
}

void ticTacToe::restart() {
    char replay;
    noOfMoves = 0;
    playersTurn = player[0];
    currentStatus = CONTINUE;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
            isAvailable[i][j] = true;
        }
    }
    cout << "Would you like to play again? (Y/N)\n";
    cin >> replay;
    if (replay == 'Y' || replay == 'y') {
        play();
    } else {
        exit(0);
    }
}

