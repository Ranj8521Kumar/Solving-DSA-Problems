#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string temp  = "";
        int count = 0;
        
        while(temp.size() < s2.size()){
            temp += s1;
            count++;
        }
        
        if(temp.find(s2) != string::npos) return count;
        
        temp += s1;
        count++;
        
        if(temp.find(s2) != string::npos){
            return count;
        }else{
            return -1;
        }
    }
};

int main(){
    Solution obj;
    string s1 = "abcd";
    string s2 = "cdabcdab";
    cout<<obj.minRepeats(s1, s2)<<endl;
    return 0;
}