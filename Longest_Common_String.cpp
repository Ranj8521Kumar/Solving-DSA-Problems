#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution solution;
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";
    
    int result = solution.longestCommonSubstr(str1, str2);
    cout << "Length of the longest common substring: " << result << endl;
    
    return 0;
}
