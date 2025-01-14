#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int toggleBits(int n , int l , int r) {
        // code here
        int x = (1<<(r)) - (1<<(l-1));
        
        return n^x;
    }
};

int main(){
    Solution obj;
    cout<<obj.toggleBits(50, 2, 5)<<endl;
    return 0;
}