#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//Buttom - Up Approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        vector<int> dp(n+1, 1);
        int longest = 1;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            longest = max(longest, dp[i]);
        }

        return  longest;
    }
};

// class Solution {
// public:
// //using recursion + brute-force
//     int n;
//     int t[2501][2501];

//     int solve(int i, int p, vector<int>& nums){
//         if(i >= n){
//             return 0;
//         }

//         if(p != -1 && t[i][p] != -1) return t[i][p];

//         //take
//         int take = 0;
//         if(p == -1 || nums[i] > nums[p]){
//             take = 1 + solve(i+1, i,  nums);
//         }

//         //skip
//         int  skip = solve(i+1, p, nums);
        
//         if(p != -1){
//             t[i][p] =  max(take, skip);
//         }

//         return max(take, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         n = nums.size();
//         memset(t, -1, sizeof(t));

//         return solve(0, -1, nums);
//     }
// };

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution sol;
    cout<<sol.lengthOfLIS(nums)<<endl;
    return 0;
}