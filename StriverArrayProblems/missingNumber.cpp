#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();

    int naturalSum = (n) * (n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    return naturalSum - sum;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums);
    return 0;
}