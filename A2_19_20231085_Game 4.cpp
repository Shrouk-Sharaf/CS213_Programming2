#include "A2_19_20231085_Game 4.h"

int main() {
    srand(time(0));
    string name1, name2;
    char mode;

    do {
        cout << "Choose the game mode:\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Computer\n";
        cout << "Enter your choice (1 or 2):\n";
        cin >> mode;
    } while (mode != '1' && mode != '2');

    cout << "Player 1, enter your name:\n";
    cin >> name1;

    WordPlayer player1(name1, ' ');
    Player<char>* players[2];

    if (mode == '1') {
        cout << "Player 2, enter your name:\n";
        cin >> name2;

        WordPlayer* player2 = new WordPlayer(name2, ' ');
        players[0] = &player1;
        players[1] = player2;
    }
    else {
        name2 = "Computer";
        WordRandomPlayer* computerPlayer = new WordRandomPlayer(' ');
        players[0] = &player1;
        players[1] = computerPlayer;
    }

    WordBoard board;

    player1.setBoard(&board);
    players[1]->setBoard(&board);

    GameManager<char> gameManager(&board, players);

    gameManager.run();
}