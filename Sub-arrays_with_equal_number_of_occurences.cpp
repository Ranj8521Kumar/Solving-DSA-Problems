#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0;
        int res = 0;

        for (auto it : arr) {
            if (it == x) cnt++;
            if (it == y) cnt--;
            if (mpp.count(cnt)) res += mpp[cnt];
            mpp[cnt]++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 1, 2, 1}; 
    int x = 1, y = 2;
    cout << solution.sameOccurrence(arr, x, y) << endl;
    return 0;
}
