#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (auto it : arr) {
            mpp[it]++;
        }
        
        int n = arr.size();
        vector<int> result(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (mpp.find(i) == mpp.end()) {
                result[i] = -1;
            } else {
                result[i] = i;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = { -1, 2, -1, 1, 3 };
    vector<int> result = sol.rearrange(arr);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
