#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        int position = 1;
        
        while(n != 0){
            if(n%2 == 1){
                return position;
            }else{
                position++;
            }
            
            n = n/2;
        }
        
        
        return 0;
    }
};

//second approach
class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        if((n & (~n + 1)) > 0){
            return log2((n & (~n + 1))) + 1;
        }
        
        return 0;
    }
};

//third approach
// User function Template for C++

class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        for(int i = 0; i<31; i++){
            if((n & (1<<i)) > 0){
                return i+1;
            }
        }
        
        
        return 0;
    }
};

int main(){
    Solution obj;
    int n = 18;
    cout<<obj.getFirstSetBit(n)<<endl;
    return 0;
}