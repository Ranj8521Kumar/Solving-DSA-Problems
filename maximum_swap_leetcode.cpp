#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int temp = num;
        while (temp != 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        reverse(digits.begin(), digits.end());

        vector<int> max_right(digits.size());
        int max_idx = digits.size() - 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > digits[max_idx]) {
                max_idx = i;
            }
            max_right[i] = max_idx;
        }

        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] != digits[max_right[i]]) {
                swap(digits[i], digits[max_right[i]]);
                break;
            }
        }

        int result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int num = 2736;
    int result = solution.maximumSwap(num);
    cout << "The maximum number after swap is: " << result << endl;
    return 0;
}
