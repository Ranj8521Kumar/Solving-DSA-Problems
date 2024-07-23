#include <bits/stdc++.h>
using namespace std;

vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    int n = nums.size();
    int maxValue = pow(2, maximumBit) - 1; //(1<<maximumBit)-1;
    int cummulativeXor = 0;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        cummulativeXor ^= nums[i];
        ans[n - 1 - i] = cummulativeXor ^ maxValue;
    }
    return ans;
}

int main()
{
    vector<int> nums = {0,1,1,3};
    vector<int> result = getMaximumXor(nums, 2);
    
    for(int it: result){
        cout<<it<<" ";
    }
    return 0;
}