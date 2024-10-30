#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        // calculating LIS
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // calculating LDS
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        // calculate MinRemoval
        int minRemoval = n;
        for(int i = 0; i < n; i++) {
            if(LIS[i] > 1 && LDS[i] > 1) {
                minRemoval = min(minRemoval, (i + 1 - LIS[i]) + (n - i - LDS[i]));
            }
        }
        return minRemoval;
    }
};

int main() {
    // Example input
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3};
    
    Solution solution;
    int result = solution.minimumMountainRemovals(nums);
    
    cout << "Minimum removals to make the array a mountain: " << result << endl;
    
    return 0;
}
