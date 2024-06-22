#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 0; i<n; i++){
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }

int main()
{
    vector<int> nums = {3, 2, 4};
    int result = maxProfit(nums);
    cout<<result;
    return 0;
}