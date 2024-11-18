#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        int n = candidates.size();

        for(int i = 0; i < 31; i++) {
            int count = 0;
            for(auto it : candidates) {
                if(it & (1 << i)) {
                    count++;
                }
            }
            result = max(result, count);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};

    int result = sol.largestCombination(candidates);
    cout << "The largest combination count with a common set bit is: " << result << endl;

    return 0;
}
