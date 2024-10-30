#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n, 1);
        for(int i = 0; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i]>nums[j]){
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        return *max_element(LIS.begin(), LIS.end());
    }
};
int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << result << endl;
    return 0;
}