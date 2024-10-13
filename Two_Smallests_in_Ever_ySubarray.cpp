#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return -1;

        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 1; i < n; i++) {
            sum = arr[i] + arr[i - 1];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

int main() {
    // Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << Solution().pairWithMaxSum(arr) << endl;
    // cout << sol.pairWithMaxSum(arr) << endl;
    return 0;
}
