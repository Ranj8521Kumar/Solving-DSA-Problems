#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        int n = strs[0].size();
        string result = "";
        for (int i = 0; i < n; i++) {
            if (strs[0][i] == strs.back()[i]) {
                result.push_back(strs[0][i]);
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"interspecies", "interstellar", "interstate"};

    cout << "Longest common prefix of [\"flower\", \"flow\", \"flight\"]: " << solution.longestCommonPrefix(strs1) << endl;
    cout << "Longest common prefix of [\"dog\", \"racecar\", \"car\"]: " << solution.longestCommonPrefix(strs2) << endl;
    cout << "Longest common prefix of [\"interspecies\", \"interstellar\", \"interstate\"]: " << solution.longestCommonPrefix(strs3) << endl;

    return 0;
}
