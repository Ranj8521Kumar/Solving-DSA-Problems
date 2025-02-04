#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            } else {
                maxSum = max(maxSum, sum);
                sum = nums[i];
            }
        }
        maxSum = max(maxSum, sum);

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 20, 30, 5, 10, 50};
    cout << "Maximum Ascending Subarray Sum: " << sol.maxAscendingSum(nums) << endl;
    return 0;
}