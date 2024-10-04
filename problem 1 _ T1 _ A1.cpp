#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int main() {
    string sentence, line;
    vector<pair<string, string>> replacements = {
            {"he", "he or she"},
            {"He", "He or she"},
            {"him", "him or her"},
            {"his", "his or her"},
            {"His", "His or her"},
            {"himself", "himself or herself"}
    };

    cout << "Enter your sentence (press Enter on an empty line to finish):\n";

    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        sentence += line + "\n";
    }

    for (const auto& replacement : replacements) {
        regex word("\\b" + replacement.first + "\\b");
        sentence = regex_replace(sentence, word, replacement.second);
    }

    // Output the final result
    cout << sentence << endl;
}
