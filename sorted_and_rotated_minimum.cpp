#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        
        //return *min_element(begin(arr), end(arr));
        
        int minElem = arr[0];
        
        for(auto it: arr){
            minElem = min(minElem, it);
        }
        
        return minElem;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout<<obj.findMin(arr)<<endl;
    return 0;
}