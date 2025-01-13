#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int i = 0;
        int j = n-1;
        
        int result = 0;
        int ans = 0;
        while(i<j){
            ans = (j-i)*min(arr[i], arr[j]);
            result = max(result, ans);
            
            if(arr[i] < arr[j]){
                i++;
            }else{
                j--;
            }
        }
        
        return result;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout<<obj.maxWater(arr)<<endl;
    return 0;
}