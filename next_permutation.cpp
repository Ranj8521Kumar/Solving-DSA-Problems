#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j = n-1;
        while(j>=0 && nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin()+i+1, nums.end());
}

int main(){
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}