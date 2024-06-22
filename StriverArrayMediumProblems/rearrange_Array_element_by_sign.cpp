#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int posIndex = 0; 
        int negIndex = 1;

        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                result[posIndex] = nums[i];
                posIndex += 2;
            }else{
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return result;
    }

int main()
{
    vector<int> nums = {3, 2, -4};
    vector<int> result = rearrangeArray(nums);
    for(int it : result){
        cout<<it<<" ";
    }
    return 0;
}