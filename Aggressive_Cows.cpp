#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        int low = 0; // Minimum possible distance
        int high = stalls[n-1] - stalls[0]; // Maximum possible distance
        
        int result = 0;
        
        int pos;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            pos = stalls[0];
            int count = 1; // Number of cows placed
            
            for(int i =  0; i<n; i++){
                
                if(stalls[i] - pos >= mid){
                    pos = stalls[i];
                    count++;
                }
                
                if(count == k){
                    result = mid;
                    break;
                }
            }
            
            if(count != k){
                high = mid - 1; // Valid distance, try for smaller
            }else{
                low = mid + 1; // Valid distance, try for larger
            }
        }
        
        return result;
    }
};

int main(){
    Solution obj;
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;
    cout<<obj.aggressiveCows(stalls, k)<<endl;
    return 0;
}