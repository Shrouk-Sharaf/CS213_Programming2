#ifndef BOARDGAME_CLASSES_H
#define BOARDGAME_CLASSES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Board {
protected:
    int rows, columns;
    T** board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, T symbol) = 0;

    virtual void display_board() = 0;

    virtual bool is_win() = 0;

    virtual bool is_draw() = 0;

    virtual bool game_is_over() = 0;
};

template <typename T>
class Player {
protected:
    string name;
    T symbol;
    Board<T>* boardPtr;  // Pointer to the board
public:
    Player(string n, T symbol);
    Player(T symbol); // For computer players

    virtual void getmove(int& x, int& y) = 0;
    T getsymbol();
    string getname();
    void setBoard(Board<T>* b);
};

template <typename T>
class RandomPlayer : public Player<T> {
protected:
    int dimension;
public:
    // Take a symbol and pass it to the parent
    RandomPlayer(T symbol);
    // Generate a random move
    virtual void getmove(int& x, int& y) = 0;
};

template <typename T>
class GameManager {
private:
    Board<T>* boardPtr;
    Player<T>* players[2];
public:
    GameManager(Board<T>*, Player<T>* playerPtr[2]);

    void run();
};

template <typename T>
GameManager<T>::GameManager(Board<T>* bPtr, Player<T>* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

template <typename T>
void GameManager<T>::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->getmove(x, y);
            while (!boardPtr->update_board(x, y, players[i]->getsymbol())) {
                players[i]->getmove(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_win()) {
                cout << players[i]->getname() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}

// Constructor for Player with a name and symbol
template <typename T>
Player<T>::Player(std::string n, T symbol) {
    this->name = n;
    this->symbol = symbol;
}

// Constructor for Player with only a symbol (e.g., for computer players)
template <typename T>
Player<T>::Player(T symbol) {
    this->name = "Computer";
    this->symbol = symbol;
}

//Constructor for RandomPlayer, passing the symbol to the parent Player class
template <typename T>
RandomPlayer<T>::RandomPlayer(T symbol) : Player<T>(symbol) {}

// Getter for player's name
template <typename T>
std::string Player<T>::getname() {
    return this->name;
}

// Getter for player's symbol
template <typename T>
T Player<T>::getsymbol() {
    return this->symbol;
}

// Method to set the board pointer in the Player class
template <typename T>
void Player<T>::setBoard(Board<T>* b) {
    this->boardPtr = b;
}

#endif //BOARDGAME_CLASSES_H