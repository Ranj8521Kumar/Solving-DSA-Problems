#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int x = a^b;
        
        return __builtin_popcount(x);
        
    }
};

// second approach
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int x = a^b;
        
        int count = 0;
        while(x > 0){
            if((x)&1 == 1){
                count++;
            }
            
            x = x>>1;
        }
        
        return count;
    }
};

//third approach
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int x = a^b;
        
        int count = 0;
        while(x > 0){
            if((x)%2 != 0){
                count++;
            }
            
            x = x>>1;
        }
        
        return count;
    }
};

////User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int x = a^b;
        
        int count = 0;
        while(x > 0){
            x = x&(x-1);//smallest set bit becomes 0
            count++;
        }
        
        return count;
    }
};

int main(){
    Solution obj;
    cout<<obj.countBitsFlip(10, 20)<<endl;
    return 0;
}