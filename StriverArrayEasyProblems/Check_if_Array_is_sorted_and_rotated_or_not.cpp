#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rotations=0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i]<nums[i-1]){
                rotations++;
            }
        }
        if(nums[n-1]>nums[0]){
            rotations++;
        }
        return rotations<=1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout<<obj.check(nums);
    if (obj.check(nums)) {
        cout << "Given Array was originally sorted in non-decreasing order and then rotated." << endl;
    } else {
        cout << "Given Array was not originally sorted in non-decreasing order and then rotated." << endl;
    }
    return 0;
}
