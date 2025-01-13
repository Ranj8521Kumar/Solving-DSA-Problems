#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        for(auto &ch: s){
            mpp[ch]++;
        }

        for(auto &it: mpp){
            if(it.second >= 3){
                int k = (it.second - 3)/2 + 1;
                mpp[it.first] = (it.second - k*2);
            }
        }

        int result = 0;
        for(auto &it: mpp){
            result += it.second;
        }

        return result;
    }
};

int main(){
    Solution obj;
    string s = "aabccabba";
    cout<<obj.minimumLength(s)<<endl;
    return 0;
}