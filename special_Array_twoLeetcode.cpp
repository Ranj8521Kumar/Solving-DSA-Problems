#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityChecks(n-1, 0);

        //for parity checks
        for(int i = 0; i<n-1; i++){
            parityChecks[i] = (nums[i]%2 != nums[i+1]%2);
        }

        //prefix sum for parity checks
        vector<int> prefix(n, 0);
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + parityChecks[i-1];
        }

        //process queries and find out special array
        vector<bool> result;
        for(const auto &q: queries){
            int from = q[0];
            int to = q[1];

            int totalPairs = to - from;
            int validPairs = prefix[to] - prefix[from];

            result.push_back(totalPairs == validPairs);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 2}, {2, 3}, {3, 4}};
    vector<bool> result = obj.isArraySpecial(nums, queries);
    for (auto x : result) {
        cout << x << endl;
    }
    return 0;
}