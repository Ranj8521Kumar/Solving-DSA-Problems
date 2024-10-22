#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countgroup(vector<int>& arr) {
        int n = arr.size();
        int mod = 1000000007;
        int xorTotal = 0;
        for (auto it : arr) {
            xorTotal ^= it;
        }
        
        if (xorTotal == 0) {
            return (int)(pow(2, n - 1) - 1) % mod;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4}; 
    cout << solution.countgroup(arr) << endl;
    return 0;
}
