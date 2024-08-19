#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        int steps = 0;
        int factor = 2;

        while (factor * factor <= n) {
            while (n % factor == 0) {
                steps += factor;
                n /= factor;
            }
            factor++;
        }

        if (n > 1) {
            steps += n;
        }

        return steps;
    }
};

int main() {
    Solution sol;
    int n = 12;
    int result = sol.minSteps(n);
    cout << "Minimum steps to reach " << n << " is " << result << endl;
    return 0;
}
