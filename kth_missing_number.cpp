#include<bits/stdc++.h>
using namespace std;

//first method
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        
        int low = 1;
        int high = arr[n-1] + k;
        
        int missing = 0;
        int result = 0;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            
            int notMissing = 0;
            //calculate how many numbers are missing upto mid using upper bound
            notMissing  = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            missing = mid - notMissing;
            
            if(missing >= k){
                high = mid - 1;
                result = mid;
            }else{
                low = mid + 1;
            }
        }
        
        return result;
    }
};

//second method
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        
        int low = 1;
        int high = arr[n-1] + k;
        
        int missing = 0;
        int result = 0;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            
            int notMissing = 0;
            for(auto &it: arr){
                if(it > mid){
                    break;
                }
                
                notMissing++;
            }
            
            missing = mid - notMissing;
            
            if(missing >= k){
                high = mid - 1;
                result = mid;
            }else{
                low = mid + 1;
            }
        }
        
        return result;
    }
};

//third method
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        
        unordered_set<int> st(arr.begin(), arr.end());
        
        int maxElem = arr[n-1];
        
        int count = 0;
        
        int i = 1;
        
        while(true){
            if(st.find(i) == st.end()){
                count++;
            }
            
            if(count == k){
                return i;
            }
            
            i++;
        }
        
        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    Solution obj;
    cout << obj.kthMissing(arr, k) << endl;

    return 0;
}