#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums){
            long long count = 0;
            map<int, int> mpp;

            int n = nums.size();
            int left = 0;
            int right = 0;

            while(right < n){
                mpp[nums[right]]++;

                while((mpp.rbegin()->first - mpp.begin()->first)>2){
                    mpp[nums[left]]--;
                    if(mpp[nums[left]] == 0){
                        mpp.erase(nums[left]);
                    }
                    left++;
                }
                count += right - left + 1;
                right++;
            }
            return count;
        }
};

int main(){
    Solution obj;
    vector<int> nums = {2, 2, 2, 2, 2};
    cout<<obj.continuousSubarrays(nums)<<endl;
    return 0;
}