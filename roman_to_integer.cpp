#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int len = s.length();
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (i < len - 1 && mpp[s[i]] < mpp[s[i+1]]) {
                result -= mpp[s[i]];
            } else {
                result += mpp[s[i]];
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    string roman1 = "III";
    string roman2 = "LVIII";
    string roman3 = "MCMXCIV";

    cout << "Roman numeral: " << roman1 << " -> Integer: " << solution.romanToInt(roman1) << endl;
    cout << "Roman numeral: " << roman2 << " -> Integer: " << solution.romanToInt(roman2) << endl;
    cout << "Roman numeral: " << roman3 << " -> Integer: " << solution.romanToInt(roman3) << endl;

    return 0;
}
