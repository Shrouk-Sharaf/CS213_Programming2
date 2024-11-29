#include "A2_19_20231085_Game 1.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    PyramidBoard board;
    Player* player1;
    Player* player2;

    int choice;
    cout << "Choose game mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    cout << "Enter your choice (1 or 2):\n";
    cin >> choice;

    string name1, name2;
    cout << "Enter name for Player 1:\n";
    cin >> name1;

    player1 = new PyramidPlayer(name1, 'X');

    if (choice == 1) {
        cout << "Enter name for Player 2:\n";
        cin >> name2;
        player2 = new PyramidPlayer(name2, 'O');
    }
    else {
        player2 = new RandomPyramidPlayer("Computer", 'O');
    }

    GameManager manager;
    manager.setBoard(&board);
    manager.setPlayers(player1, player2);

    manager.run();

    delete player1;
    delete player2;
}