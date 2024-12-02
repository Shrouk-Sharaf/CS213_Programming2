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

        WordPlayer* player2 = new WordPlayer(name2, ' '); // Player 2 (human) uses 'O'
        players[0] = &player1;
        players[1] = player2;
    } else {
        name2 = "Computer";

        WordRandomPlayer* computerPlayer = new WordRandomPlayer(' '); // Computer uses 'O'
        players[0] = &player1;
        players[1] = computerPlayer;
    }

    WordBoard board;

    player1.setBoard(&board);
    players[1]->setBoard(&board);

    GameManager<char> gameManager(&board, players);

    board.display_board();

    while (!board.game_is_over()) {
        for (int i : {0, 1}) {
            char symbol;

            if (mode == '2' && i == 1) {
                char randomLetter = 'A' + rand() % 26;  // 'A' to 'Z'

                symbol = randomLetter;
                cout << "Random player symbol: " << symbol << endl;
            } else {
                cout << players[i]->getname() << ", enter the letter you want to place:\n";
                cin >> symbol;

                symbol = toupper(symbol);

                while (!isalpha(symbol)) {
                    cout << "Invalid input. Please enter a valid letter (A-Z):\n";
                    cin >> symbol;
                    symbol = toupper(symbol);
                }
            }

            int x, y;
            players[i]->getmove(x, y);

            while (!board.update_board(x, y, symbol)) {
                cout << "Invalid move. Try again.\n";
                players[i]->getmove(x, y); // Retry position input
            }

            board.display_board();

            if (board.is_win()) {
                cout << players[i]->getname() << " wins by forming a word!\n";
                return 0;
            }
            if (board.is_draw()) {
                cout << "The game ends in a draw!\n";
                return 0;
            }
        }
    }
}