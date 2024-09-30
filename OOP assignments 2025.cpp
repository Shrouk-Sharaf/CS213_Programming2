#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int main() {
    string sentence;
    vector<pair<string, string>> replacements = {
            {"he", "he or she"},
            {"He", "He or she"},
            {"him", "him or her"},
            {"his", "his or her"},
            {"His", "His or her"}
    };
    cout << "Enter a sentence\n";
    getline(cin, sentence);
    for (const auto& replacement : replacements) {
        regex word("\\b" + replacement.first + "\\b");
        sentence = regex_replace(sentence, word, replacement.second);
    }
    cout << sentence << endl;
}
