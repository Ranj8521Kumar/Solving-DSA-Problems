#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//First Approach --> O(n) time complexity
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        unordered_map<int, pair<int, int>> mpp;

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            while(num != 0) {
                int digit = num % 10;
                sum += digit;
                num /= 10;
            }

            auto &it = mpp[sum];
            int max1 = it.first;
            int max2 = it.second;

            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2) {
                max2 = nums[i];
            }

            it = {max1, max2}; // for updating the map entry

            if(max1 && max2) {
                result = max(result, max1 + max2);
            }
        }

        return result;
    }
};

//Second Approach --> O(nlogn) time complexity
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> vec(82);
    
            for(int i = 0; i<n; i++){
                int num = nums[i];
                int sum = 0;
                while(num != 0){
                    int digit = num%10;
                    sum += digit;
                    num /= 10;
                }
    
                vec[sum].push_back(nums[i]);
            }
    
            int result = INT_MIN;
    
            for(auto &group: vec){
                int len = group.size();
                if(len > 1){
                    sort(group.begin(), group.end());
    
                    result = max(result, group[len - 1] + group[len - 2]);
                }
            }
    
            return (result == INT_MIN)? -1 : result;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {51, 71, 17, 42};
    cout << "Maximum Sum: " << sol.maximumSum(nums) << endl;
    return 0;
}