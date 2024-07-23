#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0;
    int count = 1;
    for (int j = 1; j < n; j++)
    {
        if (nums[i] == nums[j])
        {
            count++;
        }
        else
        {
            if (count > n / 3)
            {
                ans.push_back(nums[i]);
            }
            i = j;
            count = 1;
        }
    }

    if (count > n / 3)
    {
        ans.push_back(nums[n - 1]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> result = majorityElement(nums);
    for (int i = 0; i < result.size(); i++)
    {
            cout<<result[i]<<" ";
    }
    
    return 0;
}