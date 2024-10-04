#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void getFileName(string &fileName) {
    while (true) {
        cout << "Enter file name:\n";
        cin >> fileName;
        ifstream file(fileName);
        if (file) {
            file.close();
            break;
        }
        else cout << "File '" << fileName << "' not found. Please try again." << endl;
    }
}
void charByCharCompare(const string &file1, const string &file2) {
    ifstream f1(file1);
    ifstream f2(file2);
    string line1, line2;
    int lineNumber = 1;
    while (true) {
        getline(f1, line1);
        getline(f2, line2);
        if (line1 != line2) {
            cout << "Files are different at line " << lineNumber << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
            return;
        }
        if (f1.eof() && f2.eof()) {
            cout << "Files are identical." << endl;
            return;
        }
        lineNumber++;
    }
}
void wordByWordCompare(const string &file1, const string &file2) {
    ifstream f1(file1);
    ifstream f2(file2);
    string word1, word2;
    vector<string> words1, words2;
    while (f1 >> word1) words1.push_back(word1);
    while (f2 >> word2) words2.push_back(word2);
    size_t minLength = min(words1.size(), words2.size());
    for (size_t i = 0; i < minLength; ++i) {
        if (words1[i] != words2[i]) {
            cout << "Files are different at word position\n" << i + 1 << ":\n";
            cout << "File 1: " << words1[i] << "\n";
            cout << "File 2: " << words2[i] << "\n";
            return;
        }
    }
    if (words1.size() != words2.size()) cout << "Files are different in length." << endl;
    else cout << "Files are identical." << endl;
}
int main() {
    string file1, file2;
    getFileName(file1);
    getFileName(file2);
    int choice;
    while (true){
        cout << "Choose file comparison type:\n1) Character by character comparison\n2) Word by word comparison\n";
        cin >> choice;
        if (!(choice == 1 || choice == 2)) {
            cout << "Please choose a valid option" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }
    if (choice == 1) charByCharCompare(file1, file2);
    else if (choice == 2) wordByWordCompare(file1, file2);
}