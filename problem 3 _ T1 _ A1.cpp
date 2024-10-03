#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int k = 0;
    int m = 2;
    bool ok = true;
    for(int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < k; ++j) cout << ' ';
            cout << '*' << ' ';
            cout << endl;
        }
        else {
            if (ok) {
                for (int j = 0; j < k; ++j) cout << ' ';
                for (int j = 0; j < 2; ++j) cout << '*' << ' ';
            }
            else {
                for (int v = 0; v < pow(2, m); ++v) cout << '*' << ' ';
                ++m;
            }
            cout << endl;
            ok = !ok;
            k += 2;
        }
    }
    m = 2;
    for(int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < k; ++j) cout << ' ';
            cout << '*' << ' ';
            cout << endl;
        }
        else {
            if (ok) {
                for (int j = 0; j < k; ++j) cout << ' ';
                for (int j = 0; j < 2; ++j) cout << '*' << ' ';
            }
            else {
                for (int v = 0; v < 2 * pow(2, m); ++v) cout << ' ';
                for (int v = 0; v < pow(2, m); ++v) cout << '*' << ' ';
                ++m;
            }
            cout << endl;
            ok = !ok;
            k += 2;
        }
    }
}
