#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 0; i <= amount; i++) {
            for (auto coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins = {186, 419, 83, 408};
    int amount = 6249;
    
    int result = solution.coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl;

    return 0;
}
