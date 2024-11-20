#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        map<int, int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        
        int n = arr.size();
        vector<int> result;
        for(auto it: mpp){
            if(it.second > (n/3)){
                result.push_back(it.first);
            }
        }
        return result;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {3, 2, 3};
    vector<int> result = ob.findMajority(arr);
    for(auto it: result){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
