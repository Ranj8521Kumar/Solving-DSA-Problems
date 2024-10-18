#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for (auto it : nums) {
            maxOr |= it;
        }

        int count = 0;
        int totalSubsets = 1 << n;
        for (int mask = 0; mask < totalSubsets; mask++) {
            int currentOr = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }

            if (currentOr == maxOr) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5};
    int result = solution.countMaxOrSubsets(nums);
    cout << "The number of subsets with the maximum bitwise OR is: " << result << endl;
    return 0;
}
