#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(prices[j] <= prices[i]){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> prices(n);

    for(int i = 0; i<n; i++){
        cin>>prices[i];
    }

    Solution obj;

    vector<int> result = obj.finalPrices(prices);

    for(auto &it: result){
        cout<<it<<" ";
    }

    return 0;
}