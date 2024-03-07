#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string reverseWords(string &s){
        istringstream iss(s);//for spiliting the string
        string word;
        string result;
        while(iss>>word){
            reverse(word.begin(), word.end());
            result+=word+" ";
        }

        if(!result.empty()){
            result.pop_back();
        }
        return result;
    }
};

int main()
{
    Solution obj;
    string s="i am Ranjan";
    cout<<obj.reverseWords(s);
    return 0;
}