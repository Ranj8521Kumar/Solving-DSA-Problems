#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int maxValue=INT_MIN;
        int maxEndSum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxEndSum+=nums[i];
            if(maxEndSum>maxValue){
                maxValue=maxEndSum;
            }
            if(maxEndSum<0){
                maxEndSum=0;
            }
        }
        return maxValue;
    }

int main()
{
    vector<int> nums = {3, 2, 4};
    int result = maxSubArray(nums);
    cout<<result;
    return 0;
}