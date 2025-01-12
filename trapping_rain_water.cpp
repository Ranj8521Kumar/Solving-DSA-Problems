#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int result = 0;
        
        int i = 0; 
        int j = n-1;
        
        int current = 0;
        
        while(i<=j){
            if(arr[i]<=arr[j]){
                current = arr[i];
                
                while(i<=j && current >= arr[i]){
                    if(arr[i] > current){
                        result += 0;
                    }else{
                        result += (current - arr[i]);
                    }
                    
                    i++;
                }
                
            }else{
                current = arr[j];
                while(i<=j && current >= arr[j]){
                    if(arr[j] > current){
                        result += 0;
                    }else{
                        result += (current - arr[j]);
                    }
                    
                    j--;
                }
            }
        }
        
        return  result;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    Solution obj;
    cout<<obj.maxWater(arr)<<endl;
}