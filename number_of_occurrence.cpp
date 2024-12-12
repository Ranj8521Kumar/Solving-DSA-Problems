#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        unordered_map<int, int> mpp;
        
        for(auto it: arr){
            mpp[it]++;
        }
        
        return mpp[target];
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    cout<<obj.countFreq(arr, target)<<endl;
    return 0;
}