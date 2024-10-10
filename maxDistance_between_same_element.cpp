#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        int maxDistance = 0;
        unordered_map<int, pair<int, int>> mpp;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (mpp.find(arr[i]) == mpp.end()) {
                mpp[arr[i]] = {i, i};
            }
            mpp[arr[i]].second = i;
        }
        
        for (auto it : mpp) {
            maxDistance = max(maxDistance, it.second.second - it.second.first);
        }
        return maxDistance;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 2, 5, 1};
    Solution sol;
    int result = sol.maxDistance(arr);
    cout << "Maximum Distance: " << result << endl;
    return 0;
}
