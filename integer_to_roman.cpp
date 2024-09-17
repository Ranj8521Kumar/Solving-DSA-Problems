#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string romanNo = "";
        for (int i = 0; i < 13; i++) {
            if (num == 0) {
                break;
            }

            int times = num / val[i];
            while (times--) {
                romanNo += roman[i];
            }
            num %= val[i];
        }

        return romanNo;
    }
};

int main() {
    Solution solution;

    int num1 = 3;
    int num2 = 58;
    int num3 = 1994;

    cout << "Integer: " << num1 << " -> Roman numeral: " << solution.intToRoman(num1) << endl;
    cout << "Integer: " << num2 << " -> Roman numeral: " << solution.intToRoman(num2) << endl;
    cout << "Integer: " << num3 << " -> Roman numeral: " << solution.intToRoman(num3) << endl;

    return 0;
}
