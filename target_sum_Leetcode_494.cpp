#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //using recursion -> Brute - Force Approach
    int solve(vector<int>& nums, int target, int i, int sum){
        if(i>=nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        //add
        int leftSum = solve(nums, target, i+1, sum + nums[i]);
        //substract
        int rightSum = solve(nums, target, i+1, sum - nums[i]);

        return leftSum + rightSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};

class Solution {
public:
    //using recursion and memoization
    unordered_map<string, int> mpp; //for memoization

    int solve(vector<int>& nums, int target, int i, int sum, bool isPlus){
        if(i>=nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        string key = to_string(i)+','+to_string(sum);

        if(mpp.find(key) != mpp.end()){
            return mpp[key];
        }

        //add
        int leftSum = solve(nums, target, i+1, sum + nums[i], isPlus);
        //substract
        int rightSum = solve(nums, target, i+1, sum - nums[i], !isPlus);

        return mpp[key] = leftSum + rightSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0, 1);
    }
};

class Solution {
public:
    //using recursion and memoization without use unordered_map
    int S; //total sum

    int solve(vector<int>& nums, int target, int i, int sum, vector<vector<int>>& t){
        if(i==nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][sum + S] != INT_MIN) return t[i][sum + S];

        //add
        int leftSum = solve(nums, target, i+1, sum + nums[i], t);
        //substract
        int rightSum = solve(nums, target, i+1, sum - nums[i], t);

        return t[i][sum + S] = leftSum + rightSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n =  nums.size();
        S = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> t(n+1, vector<int>(2*S+1, INT_MIN));
        
        return solve(nums, target, 0, 0, t);
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout<<obj.findTargetSumWays(nums, target)<<endl;
    return 0;
}