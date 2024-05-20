#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
            long long total = 0;
            int left= 0;
            int max_freq = 0;

            for(int right = 0; right< nums.size(); right++){
                total += nums[right];

                while((long long)(nums[right])*(right-left+1)-total>k){
                    total = total - nums[left];
                    ++left;
                }

                max_freq = max(max_freq, (right - left +1));
            }
            return max_freq;
    }

int main()
{
    vector<int> arr = {1,2,4};
    int k = 5;
    cout<<maxFrequency(arr, k);
    return 0;
}