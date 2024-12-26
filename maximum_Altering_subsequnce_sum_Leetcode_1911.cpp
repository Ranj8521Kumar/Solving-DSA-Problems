#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //brute - force Approach
    long long solve(vector<int>& nums, int n, int i, bool isEven) {
        if (i >= n) {
            return 0;
        }

        
        int take = (isEven?nums[i]:-nums[i]) + solve(nums, n, i + 1, !isEven);
        int notTake = solve(nums, n, i + 1, isEven);

        return max(take, notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        return solve(nums, n, 0, true);
    }
};

// class Solution {
// public:
//     //recursion + memoization
//     long long t[100001][2];
//     long long solve(vector<int>& nums, int n, int i, bool isEven) {
//         if (i >= n) {
//             return 0;
//         }

//         if(t[i][isEven] != -1) return t[i][isEven];
        
//         long long take = (isEven?nums[i]:-nums[i]) + solve(nums, n, i + 1, !isEven);
//         long long notTake = solve(nums, n, i + 1, isEven);

//         return t[i][isEven] = max(take, notTake);
//     }

//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1) {
//             return nums[0];
//         }

//         memset(t, -1, sizeof(t));

//         return solve(nums, n, 0, true);
//     }
// };

// class Solution {
// public:
// //using buttom - Approach
//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();

//         long long t[100001][2];

//         //0 -> even
//         //1 -> odd

//         for(int i = 1; i<n+1; i++){
//             t[i][0] = max((t[i-1][1] - nums[i-1]), t[i-1][0]);//for even length

//             t[i][1] = max((t[i-1][0] + nums[i-1]), t[i-1][1]);//for odd length
//         }

//         return max(t[n][0], t[n][1]);
//     }
// };

int main() {
    Solution sol;
    vector<int> nums = {6, 2, 1, 2, 4, 5};
    cout << sol.maxAlternatingSum(nums) << endl;

    return 0;
}