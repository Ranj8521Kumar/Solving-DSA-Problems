#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        
        int i = 0;
        int lowest = INT_MAX;
        int maxProfit = 0;;
        
        while(i<n){
            lowest = min(lowest, prices[i]);
            maxProfit = max(maxProfit,  prices[i] - lowest);
            i++;
        }
        
        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {1, 5, 3, 8, 12};
    cout<<obj.maximumProfit(prices)<<endl;
    return 0;
}