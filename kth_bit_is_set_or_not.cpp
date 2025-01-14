#include<bits/stdc++.h>
using namespace std;

//first approach
//User function Template for C++

// User function Template for C++

class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        int position = 0;
        while(n != 0){
            if(position == k){
                if(n%2 == 1){
                    return 1;
                }else{
                    return 0;
                }
            }
            
            position++;
            n /= 2;
        }
        
        return 0;
    }
};
//second approach
// class Solution {
//   public:
//     // Function to check if Kth bit is set or not.
//     bool checkKthBit(int n, int k) {
//         // Your code here
//         // It can be a one liner logic!! Think of it!!
//         if((n & (1<<k)) > 0) return 1;
        
//         return 0;
//     }
// };

int main(){
    Solution obj;
    cout<<obj.checkKthBit(4, 0)<<endl;
    return 0;
}