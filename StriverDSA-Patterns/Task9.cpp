#include <iostream>
using namespace std;

void pattern9(int n) {
    // Upper half of the diamond
    for (int i = 1; i <= n; i++) {
        //spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        //stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        //spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        cout << endl;
    }

    // Lower half of the diamond
    for (int i = n ; i >= 1; i--) {
        //spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        //stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        //spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    pattern9(n);
    return 0;
}
