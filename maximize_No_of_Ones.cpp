#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left = 0;
        int maxCount = 0;
        int zeroCount  = 0;
        
        int n = arr.size();
        
        for(int right = 0; right < n;  right++){
            if(arr[right] == 0){
                zeroCount++;
            }
            
            while(zeroCount > k){
                if(arr[left] ==  0){
                    zeroCount--;
                }
                left++;
            }
            
            maxCount =  max(maxCount, (right - left + 1));
        }
        
        return maxCount;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 0, 0, 1, 1, 0, 1};
    int k = 2;
    cout<<obj.maxOnes(arr, k)<<endl;
    return 0;
}