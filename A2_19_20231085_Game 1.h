#ifndef PYRAMID_TICTACTOE_H
#define PYRAMID_TICTACTOE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Board {
public:
    virtual void display() = 0;
    virtual bool isValidMove(int x, int y) = 0;
    virtual bool updateBoard(int x, int y, char symbol) = 0;
    virtual bool isWin() = 0;
};

class Player {
public:
    string name;
    char symbol;

    Player(const string& name, char symbol) : name(name), symbol(symbol) {}
    virtual void getMove(int& x, int& y) = 0;
    virtual ~Player() {}
};

class GameManager {
    Board* board;
    Player* players[2];

public:
    void setBoard(Board* brd) {
        board = brd;
    }

    void setPlayers(Player* player1, Player* player2) {
        players[0] = player1;
        players[1] = player2;
    }

    void run() {
        int x, y;
        board->display();
        while (true) {
            for (int i = 0; i < 2; ++i) {
                cout << endl;
                cout << players[i]->name << "'s turn (" << players[i]->symbol << ")" << endl;
                players[i]->getMove(x, y);
                while (!board->updateBoard(x, y, players[i]->symbol)) {
                    cout << "Invalid move. Try again." << endl;
                    players[i]->getMove(x, y);
                }
                board->display();
                if (board->isWin()) {
                    cout << players[i]->name << " wins!" << endl;
                    return;
                }
                if (isDraw()) {
                    cout << "It's a draw!" << endl;
                    return;
                }
            }
        }
    }

    bool isDraw() {
        // Check if all positions on the board are filled
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < (5 - 2 * i); ++j) {
                if (board->isValidMove(i, j)) {
                    return false; // There's at least one valid move left
                }
            }
        }
        return true; // No valid moves left, it's a draw
    }
};

class PyramidBoard : public Board {
    char board[3][5];

public:
    PyramidBoard() {
        // Initialize the board with spaces
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void display() override {
        int rows = 3;  // Number of rows in the triangle
        // Print from bottom to top
        for (int i = rows - 1; i >= 0; --i) {
            // Print leading spaces for alignment
            for (int spaces = 0 ; spaces < 2 * (rows - 1); ++spaces)
                cout << ' ';
            // Print cells for the current row
            for (int j = 0; j < (5 - 2 * i); ++j)
                cout << (board[i][j] != ' ' ? board[i][j] : '.') << ' '; // Print the symbol or a placeholder
            cout << endl; // Move to the next line after finishing the row
            --rows;
        }
    }

    bool isValidMove(int x, int y) override {
        return x >= 0 && x < 3 && y >= 0 && y < (5 - 2 * x) && board[x][y] == ' ';
    }

    bool updateBoard(int x, int y, char symbol) override {
        if (isValidMove(x, y)) {
            board[x][y] = symbol;
            return true;
        }
        return false;
    }

    bool isWin() override {
        return checkHorizontal() || checkVertical() || checkDiagonal();
    }

private:
    bool checkHorizontal() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < (5 - 2 * i) - 2; ++j) {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')
                    return true;
            }
        }
        return false;
    }

    bool checkVertical() {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ' && board[2][0] != '.')
            return true;
        else
            return false;
    }

    bool checkDiagonal() {
        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ' && board[0][0] != '.') return true;
        if (board[0][4] == board[1][2] && board[1][2] == board[2][0] && board[0][4] != ' ' && board[0][4] != '.') return true;

        return false;
    }

};

class PyramidPlayer : public Player {
public:
    PyramidPlayer(const string& name, char symbol) : Player(name, symbol) {}

    void getMove(int& x, int& y) override {
        cout << "Enter your move (row):\n";
        cin >> x ;
        cout << "Enter your move (column):\n";
        cin >> y;
    }
    ~PyramidPlayer(){
        delete this;
    }
};

class RandomPyramidPlayer : public PyramidPlayer {
public:
    RandomPyramidPlayer(const string& name, char symbol) : PyramidPlayer(name, symbol) {}

    void getMove(int& x, int& y) override {
        do {
            x = rand() % 3;
            y = rand() % (5 - 2 * x);
        } while (!isValidMove(x, y));
    }

    bool isValidMove(int x, int y) {
        return x >= 0 && x < 3 && y >= 0 && y < (5 - 2 * x);
    }
};

#endif