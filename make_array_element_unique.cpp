#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int incCount = 0;
        
        for(int i = 1; i<n; i++){
            if(arr[i] <= arr[i-1]){
                int inc = arr[i-1] - arr[i]  +  1;
                
                incCount += inc;
                
                arr[i] = arr[i-1] + 1;
            }
        }
        
        return incCount;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {3, 2, 1, 2, 1, 7};
    cout<<obj.minIncrements(arr)<<endl;
    return 0;
}