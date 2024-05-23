#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr, int n)
    {
        int maxi = 0;
        for(int i = 0; i< n; i++){
            if(arr[maxi]<arr[i]){
                maxi = i;
            }
        }
        return arr[maxi];
    }

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    int n = nums.size();
    cout<<largest(nums, n);
    return 0;
}