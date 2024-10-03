#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Player {
    string name;
    int score;
};

int main() {
    vector<Player> Players;
    string name;
    int score, choice;

    while (true) {
        cout << "Choose one of the following:\n1) Add a score\n2) Print top 10 scores\n3) Search a player's highest score\n4) Exit the program\n";
        cin >> choice;

        if (!(choice == 1 || choice == 2 || choice == 3 || choice == 4)) {
            cout << "Please choose a valid option" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (choice == 4) {
            cout << "Exiting the program...." << endl;
            break;
        }
        else if (choice == 1) {
            char innerChoice;
            do {
                cout << "Enter the player's name\n";
                cin.ignore();
                getline(cin, name);
                cout << "Enter their score\n";
                cin >> score;
                Player newPlayer = {name, score};
                Players.push_back(newPlayer);

                sort(Players.begin(), Players.end(), [](Player a, Player b) {
                    return a.score > b.score;
                });

                if (Players.size() > 10) Players.pop_back();

                while (true) {
                    cout << "Do you want to add another score? (y/n)\n";
                    cin >> innerChoice;

                    if (innerChoice == 'y' || innerChoice == 'Y' || innerChoice == 'n' || innerChoice == 'N') break;
                    else cout << "Invalid input. Please choose either y or n." << endl;
                }

                if (innerChoice == 'n' || innerChoice == 'N') break;

            } while (innerChoice == 'y' || innerChoice == 'Y');
        }
        else if (choice == 2) {
            sort(Players.begin(), Players.end(), [](Player a, Player b) {
                return a.score > b.score;
            });
            cout << "Top 10 scores:\n";
            for (int i = 0; i < min(10, (int)Players.size()); i++) {
                cout << i + 1 << ". " << Players[i].name << " - " << Players[i].score << endl;
            }
        }
        else if (choice == 3) {
            cout << "Enter the player's name\n";
            cin.ignore();
            getline(cin, name);

            int maxScore = -1;
            bool found = false;

            for (auto& player : Players) {
                if (player.name == name) {
                    found = true;
                    maxScore = max(maxScore, player.score);
                }
            }

            if (found) cout << name << "'s highest score: " << maxScore << endl;
            else cout << name << " not found in the top scores" << endl;
        }
    }
}
