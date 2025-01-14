#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        return (n)|(1<<k);
    }
};

int main(){
    Solution obj;
    cout<<obj.setKthBit(4, 1)<<endl;
    return 0;
}