#include<bits/stdc++.h>
using namespace std;

long long pairWithMaxSum(long long Arr[], long long N)
    {
        long long maxSum = INT_MIN;
        for(int i = 0; i<N-1; i++){
            long long currentSum = Arr[i] + Arr[i+1];
            if(currentSum>maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
    }    

int main()
{
    long long nums[] = {3, 2, 4};
    long long result = pairWithMaxSum(nums, 3);
    cout<<result;
    return 0;
}