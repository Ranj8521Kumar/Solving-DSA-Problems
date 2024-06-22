#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxi = LONG_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max(maxi, 0LL);
}

int main()
{
    vector<int> nums = {3,2,4};
    cout<<maxSubarraySum(nums, 3);
    return 0;
}