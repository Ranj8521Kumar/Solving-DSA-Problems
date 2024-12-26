#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//recursion with memoization
    int t[101];

    int solve(int i, int n, vector<int>& nums){
        if(i > n) return 0;

        if(t[i] != -1) return t[i];

        int steal = nums[i] + solve(i+2, n, nums);
        int skip = solve(i+1, n, nums);

        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];//special case, if only one house

        memset(t, -1, sizeof(t));
        int withZeroIindexedHouse = solve(0, n-2, nums);// can steal till n-2 indexed house
        memset(t,-1, sizeof(t));
        int withOutZeroIindexedHouse = solve(1, n-1, nums);// can steal till n-1 indexed house

        return max(withZeroIindexedHouse, withOutZeroIindexedHouse);
    }
};

//Buttom - Up Approach 
class Solution {
public:
//using buttom - up approach
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];//if only one house

        //steal first house - have we not taken last house
        vector<int> t(n+1, -1);
        t[0] =  0;

        for(int i = 1; i<=n-1; i++){//if steal first house
            int steal = nums[i-1] + ((i>=2)?t[i-2]:0);
            int skip = t[i-1]; 

            t[i] = max(steal, skip);
        }

        int stealFirstHouse = t[n-1];

        //skip first house - have we taken last house
        t = vector<int> (n+1, -1);
        t[0] =  0;
        t[1] = 0; //since sip first house

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + (t[i-2]);
            int skip = t[i-1];

            t[i] = max(steal, skip);
        }

        int skipFirstHouse = t[n];

        return max(stealFirstHouse, skipFirstHouse);
    }
};

//Buttom - Up Approach with constant space
class Solution {
public:
//using buttom - up approach with constant space
    int solve(int n, vector<int>& nums){
        if(n == 1){
            return nums[0];
        }

        int prevPrev = 0;
        int prev = nums[0];

        int maxProfit;

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + prevPrev;
            int skip = prev;

            maxProfit = max(steal, skip);

            prevPrev = prev;
            prev = maxProfit;;
        }

        return maxProfit;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        return solve(n, nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,2};
    cout << sol.rob(nums) << endl;

    return 0;
}