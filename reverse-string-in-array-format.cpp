#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-(i+1)]);
        }
        for(int i=0;i<n; i++){
            cout<<s[i]<<" ";
        }
    }
};

int main()
{
    Solution obj;
    vector<char> s={'a','b','c','A','B','C'};
    obj.reverseString(s);
    return 0;
}