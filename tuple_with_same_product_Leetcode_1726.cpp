#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            unordered_map<int, int> mpp;
    
            for(int i = 0; i<n-1; i++){
                for(int j = i+1; j<n; j++){
                    int product = nums[i]*nums[j];
    
                    ans += 8*mpp[product];
    
                    mpp[product]++;
                }
            }
    
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4, 6};
    cout << sol.tupleSameProduct(nums) << endl;
    return 0;
}