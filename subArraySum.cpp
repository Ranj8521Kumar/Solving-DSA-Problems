#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];

            if(prefixSum.find(sum - tar) != prefixSum.end()){
                count += prefixSum[sum - tar];

            }
            prefixSum[sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 2, -1, 2, 3};
    int target = 5;
    int result = sol.subArraySum(arr, target);
    cout << "Number of subarrays with sum " << target << " is: " << result << endl;
    return 0;
}
