#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProductSubArray(vector<int>& arr){
        int n= arr.size();
        if(n==0){
            return 0;
        }

        int maxp=arr[0];
        int minp=arr[0];
        int result=maxp;
        for (int i = 1; i < n; i++)
        {
            int prev_max=maxp;
            int prev_min=minp;
            maxp=max(arr[i],max(arr[i]*prev_max,arr[i]*prev_min));
            minp=min(arr[i],min(arr[i]*prev_max,arr[i]*prev_min));
            result=max(result,maxp);
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr={2,3,-2,4};
    cout<<"Maximum Product SubArray: "<<obj.maxProductSubArray(arr)<<endl;
    return 0;
}