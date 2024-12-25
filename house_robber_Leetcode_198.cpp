#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//Brute - force approach
    int solve(vector<int>& nums, int i, int n){
        if(i>=n) return 0;

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return max(steal, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
};

class Solution {
public:
//recursion + memoization
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i>=n) return 0;

        if(t[i] != -1) return t[i];

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};

class Solution {
public:
// Buttom - Up Apprach
    int solve(vector<int>& nums, vector<int>& arr, int n){
        arr[0] = 0;
        arr[1] = nums[0];

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + arr[i-2];
            int skip = arr[i-1];

            arr[i] = max(steal, skip);
        }

        return arr[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1);

        return solve(nums, arr, n);
    }
};

//driver code
int main(){
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<sol.rob(nums)<<endl;
    return 0;
}