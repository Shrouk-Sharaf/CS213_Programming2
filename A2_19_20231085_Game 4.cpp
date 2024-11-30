#include "A2_19_20231085_Game 4.h"

int main() {
    srand(time(0));
    string name1, name2;
    char mode;

    // Prompt the user to select the game mode
    cout << "Choose the game mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    cout << "Enter your choice (1 or 2):\n";
    cin >> mode;

    while (mode != '1' && mode != '2') {
        cout << "Invalid choice. Please enter 1 for Player vs Player or 2 for Player vs Computer:\n";
        cin >> mode;
    }

    // Prompt player 1 for their name
    cout << "Player 1, enter your name:\n";
    cin >> name1;

    // Initialize players
    WordPlayer player1(name1, ' ');
    Player<char>* players[2];

    if (mode == '1') {
        // Player vs Player Mode
        cout << "Player 2, enter your name:\n";
        cin >> name2;

        WordPlayer* player2 = new WordPlayer(name2, ' '); // Player 2 (human) uses 'O'
        players[0] = &player1;
        players[1] = player2;
    } else {
        // Player vs Computer Mode
        name2 = "Computer";

        WordRandomPlayer* computerPlayer = new WordRandomPlayer(' '); // Computer uses 'O'
        players[0] = &player1;
        players[1] = computerPlayer;
    }

    // Initialize the board
    WordBoard board;

    // Set the board for players
    player1.setBoard(&board);
    players[1]->setBoard(&board);

    // Create the game manager
    GameManager<char> gameManager(&board, players);

    board.display_board();

    while (!board.game_is_over()) {
        for (int i : {0, 1}) {
            char symbol;

            // If it's a computer's turn, don't ask for input
            if (mode == '2' && i == 1) {
                char randomLetter = 'A' + rand() % 26;  // 'A' to 'Z'

                symbol = randomLetter;  // Set the symbol to the random letter
                cout << "Random player symbol: " << symbol << endl;
            } else {
                // Prompt player for their move
                cout << players[i]->getname() << ", enter the letter you want to place:\n";
                cin >> symbol;

                // Convert the letter to uppercase
                symbol = toupper(symbol);

                // Ensure the symbol is a valid character
                while (!isalpha(symbol)) {
                    cout << "Invalid input. Please enter a valid letter (A-Z):\n";
                    cin >> symbol;
                    symbol = toupper(symbol); // Convert again to uppercase
                }
            }

            // Get the position using the getmove function
            int x, y;
            players[i]->getmove(x, y);

            // Validate and update the board
            while (!board.update_board(x, y, symbol)) {
                cout << "Invalid move. Try again.\n";
                players[i]->getmove(x, y); // Retry position input
            }

            // Display updated board
            board.display_board();

            // Check for win or draw
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