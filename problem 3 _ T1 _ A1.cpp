#include <iostream>
using namespace std;
void pattern(int n, int spaces) {
    if (n == 1) {
        cout << string(spaces, ' ') << "*" << endl;
        return;
    }
    pattern(n / 2, spaces);
    cout << string(spaces, ' ');
    for (int i = 0; i < n; ++i) cout << "* ";
    cout << endl;
    pattern(n / 2, spaces + n);
}

int main() {
    int n, initialSpaces;
    while (true){
        cout << "Enter the size of the pattern (must be a power of 2):\n";
        cin >> n;
        if (n <= 0 || (n & (n - 1)) != 0) cout << "Error: The size of the pattern must be a positive power of 2.\n\n";
        else break;
    }
    cout << "Enter the initial number of spaces:\n";
    cin >> initialSpaces;
    pattern(n, initialSpaces);
}