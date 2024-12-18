#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if(n < k){
            return -1;
        }
        
        int result = -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0); // 0 is the initial value
        
        if(k == 1){
            return high;
        }
        
        while(low<=high){
            int mid = low + (high - low)/2;
            
            int student = 1;
            int sum = 0;
            
            for(int i = 0; i<n; i++){
                sum += arr[i];
                if(sum > mid){
                    student++;
                    
                    sum = arr[i];  //initialize for new student
                }
            }
            
            if(student > k){
                low = mid + 1;
            }else{
                result = mid;
                high = mid - 1;
            }
        }
        
        return result;
        
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;
    
    Solution ob;
    cout<<ob.findPages(arr, k)<<endl;
    
    return 0;
}