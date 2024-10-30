#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        
        int count = 0;
        
        for(auto it: arr){
            if(it - k > 0 && mpp.find(it - k) != mpp.end()){
                count += mpp[it - k];
            }
        }
        
        return count;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    Solution obj;
    cout << obj.countPairsWithDiffK(arr, k) << endl;
    return 0;
}
