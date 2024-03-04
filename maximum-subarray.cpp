//Kadane's Algorithm to find maximum subArray Sum

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSubArray(vector<int>& arr){
        int maxValue=INT_MIN;
        int maxEndSum=0;
        for (int i = 0; i < arr.size(); i++)
        {
            maxEndSum+=arr[i];
            if(maxEndSum>maxValue){
                maxValue=maxEndSum;
            }
            if(maxEndSum<0){
                maxEndSum=0;
            }
        }
        return maxValue;
    }
};

int main()
{
    Solution obj;
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"MaxSubArray = "<<obj.maxSubArray(arr)<<endl;
    return 0;
}