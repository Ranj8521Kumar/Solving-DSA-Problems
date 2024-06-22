#include<bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }

    vector<int> dp(n, 1);

    int longest = 1;

    // Build the dp array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(longest, dp[i]);
    }

    return longest;
}


int main()
{
    vector<int> nums = {3,2,4};
    cout<<lis(nums);
    return 0;
}