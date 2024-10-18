#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getSingle(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (auto it : arr) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            if (it.second % 2 != 0) {
                return it.first;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 3, 2, 2, 4, 4, 4};  
    int result = solution.getSingle(arr);
    cout << "The element that appears an odd number of times is: " << result << endl;
    return 0;
}
