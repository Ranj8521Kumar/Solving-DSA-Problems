#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int x = m^n;
        
        //find right most set bit that is our result
        for(int  i = 0; i<31; i++){
            if((x & (1<<i)) > 0) return i+1;
        }

        return -1;
        
    }
};

//second approach
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int position = 1;
        while(m != 0 || n != 0){
            if(m%2 != n%2){
                return position;
            }else{
                position++;
                m /= 2;
                n /= 2;
            }
        }
        
        return -1;
    }
};

//third approach
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int position = 1;
        while(m != 0 || n != 0){
            if(m%2 != n%2){
                return position;
            }else{
                position++;
                m = m>>1;
                n = n>>1;
            }
        }
        
        return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        Solution ob;
        cout<<ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;
}