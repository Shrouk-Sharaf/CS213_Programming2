#include <iostream>
#include <cmath>
using namespace std;
void pattern(int n, int i) {
    if (n == 1) {
        cout << string(i, ' ') << "*" << endl;
        return;
    }
    pattern(n / 2, i);
    cout << string(i, ' ');
    for (int x = 0; x < n; ++x) cout << "* ";
    cout << endl;
    pattern(n / 2, i + n);
}

int main() {
    int n, initialSpaces;
    while (true){
        cout << "Enter the size of the pattern (must be a power of 2):\n";
        cin >> n;
        if (n <= 0 || floor(log2(n)) != ceil(log2(n))) cout << "Error: The size of the pattern must be a positive power of 2.\n\n";
        else break;
    }
    cout << "Enter the initial number of spaces:\n";
    cin >> initialSpaces;
    pattern(n, initialSpaces);
}