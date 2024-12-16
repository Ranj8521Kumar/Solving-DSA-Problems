#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        
        //use custom comparator for lexicographical sorting of numbers
        
        int n = arr.size();
        
        vector<string> str(n);
        
        for(int i = 0; i<n; i++){
            str[i] =  to_string(arr[i]);
        }
        
        //lexicographical sort
        sort(str.begin(), str.end(), [](string& x, string& y){
            return (x+y)>(y+x);
        });
        
        string result = "";
        
        for(auto &st: str){
            result += st;
        }
        
        int i = 0;
        
        while(i<n){
            if(result[i] != '0'){
                break;
            }
            i++;
        }
        
        return (result.substr(i)=="")?"0":result.substr(i);
    }
};

int main(){
    Solution obj;
    vector<int> arr = {3, 30, 34, 5, 9};
    cout<<obj.findLargest(arr)<<endl;
    return 0;
}