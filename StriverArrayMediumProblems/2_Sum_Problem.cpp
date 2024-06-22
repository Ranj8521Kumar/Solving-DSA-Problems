#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int more = target - num;

        if (mpp.find(more) != mpp.end())
        {
            return {mpp[more], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {3,2,4};
    vector<int> result = twoSum(nums, 6);
    for (int it : result)
    {
        cout << it << " ";
    }
    return 0;
}