#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int maxWidthRamp = 0;
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                maxWidthRamp = max(maxWidthRamp, j - st.top());
                st.pop();
            }
        }
        return maxWidthRamp;
    }
};

int main() {
    vector<int> nums = {6, 0, 8, 2, 1, 5}; // Example array

    Solution sol;
    int result = sol.maxWidthRamp(nums);
    
    cout << "Maximum Width Ramp: " << result << endl;
    
    return 0;
}
