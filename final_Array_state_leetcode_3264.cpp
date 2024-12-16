#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            auto minElem = min_element(nums.begin(), nums.end());
            int idx = minElem - nums.begin();
            int  num = *minElem * multiplier;

            nums[idx] = num;
        }

        return nums;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    int multiplier = 2;
    vector<int> result = obj.getFinalState(nums, k, multiplier);

    for(auto &num: result){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}