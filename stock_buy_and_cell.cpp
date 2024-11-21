#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int maxProfit = 0;
        
        int i = 0;
        int j = 1;
        
        while(j<n){
            if(prices[j]<prices[j-1]){
                maxProfit += prices[j-1] -  prices[i];
                i = j;
            }
            j++;
        }
        maxProfit += prices[n-1] -  prices[i];
        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {1, 5, 3, 8, 12};
    cout<<obj.maximumProfit(prices)<<endl;
    return 0;
}