#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        if(n==0) return 0;
        
        int maxProduct = arr[0];
        int minProduct = arr[0];
        int result = arr[0];
        
        for(int i = 1; i<n; i++){
            int it = arr[i];
            if(it<0){
                swap(maxProduct,minProduct);
            }
            
            maxProduct = max(it, maxProduct*it);
            minProduct = min(it, minProduct*it);
            
            result = max(result, maxProduct);
        }
        
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {6, -3, -10, 0, 2};
    cout<<obj.maxProduct(arr);
    return 0;
}