#include<bits/stdc++.h>
using namespace std;

// First approach
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

// Second approach
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //using monotonic stack
        //and optimixed approach

        int n = prices.size();
        stack<int> st;
        vector<int> result(n);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }

            if(!st.empty()){
                result[i] = prices[i] - st.top();
            }else{
                result[i] = prices[i];
            }

            st.push(prices[i]);
        }

        return result;
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