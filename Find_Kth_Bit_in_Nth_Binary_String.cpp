#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string invert(string str) {
        for (auto &ch : str) {
            ch = (ch == '0') ? '1' : '0';
        }
        return str;
    }

    string Sn(int n) {
        if (n == 1) {
            return "0";
        } else {
            string prev = Sn(n - 1);
            return prev + "1" + reverse(invert(prev));
        }
    }

    string reverse(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }

    char findKthBit(int n, int k) {
        string str = Sn(n);
        return str[k - 1];
    }
};

int main() {
    Solution solution;
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    char result = solution.findKthBit(n, k);
    cout << "The " << k << "th bit of Sn(" << n << ") is: " << result << endl;

    return 0;
}
