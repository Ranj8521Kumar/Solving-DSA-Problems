#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();

        if (n < k) {
            return false;
        }

        unordered_map<char, int> mpp;
        for (auto &ch : s) {
            mpp[ch]++;
        }

        int oddCount = 0;
        for (auto &it : mpp) {
            if (it.second % 2 != 0) {
                oddCount++;
            }
        }

        if (oddCount > k) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "annabelle";
    int k = 2;

    if (solution.canConstruct(s, k)) {
        cout << "Yes, it is possible to construct " << k << " palindrome strings from the given string." << endl;
    } else {
        cout << "No, it is not possible to construct " << k << " palindrome strings from the given string." << endl;
    }

    return 0;
}