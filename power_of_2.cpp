#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        // code here
        for(int i = 0; i<=31; i++){
            if((1<<i) == n){
                return true;
            }
        }
        
        return false;
    }
};

//second approach
class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        // code here
        return __builtin_popcount(n) == 1; //this function return the
        //number of set bits in an integer
    }
};

int main(){
    Solution obj;
    cout<<obj.isPowerofTwo(8)<<endl;
    return 0;
}