#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    int maxLen = 0;
    unordered_map<int, int> sumMap;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + A[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if (sumMap.find(sum) != sumMap.end())
        {
            maxLen = max(maxLen, i - sumMap[sum]);
        }
        else
        {
            sumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> nums = {1, -2, 1, 3};
    cout<<maxLen(nums, 4);
    return 0;
}