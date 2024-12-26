#include<bits/stdc++.h>
using namespace std;

//First Approach
class Solution {
public:
//Buttom - Up Approach
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        int longest = 1;
        vector<int>  dp(n+1, 1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            longest = max(longest, dp[i]);
        }

        return longest;
    }
};

//Second Approach
class Solution {
public:
//Recursion + Memoization Approach
    int n;
    int t[1001][10001];

    int solve(int i, int p, vector<vector<int>>& pairs){
        if(i >= n) return 0;

        if(p != -1 && t[i][p] != -1) return t[i][p];

        //take
        int take = 0;
        if(p == -1 || pairs[i][0] > pairs[p][1]){
            take = 1 + solve(i+1, i, pairs);
        }

        //skip
        int skip = solve(i+1, p, pairs);

        if(p != -1){
            t[i][p] = max(take, skip);
        }

        return max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(t, -1, sizeof(t));

        sort(pairs.begin(), pairs.end());

        return solve(0, -1, pairs);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> pairs = {{1,2}, {2,3}, {3,4}};
    cout << sol.findLongestChain(pairs) << endl;
    return 0;
}