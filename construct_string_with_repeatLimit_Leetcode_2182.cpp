#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();

        vector<int> alphabets(26, 0);

        for(int i = 0; i<n; i++){
            alphabets[s[i] - 'a']++;
        }

        string result = "";
    
        for(int i = 25; i>=0; ){
            if(alphabets[i] > 0){
                int useCount = min(repeatLimit, alphabets[i]);

                //add upto usecount for that current character
                result.append(useCount, (char)(i + 'a'));

                alphabets[i] -= useCount;

                if(alphabets[i] > 0){
                    int j = i - 1;
                    while(j>=0 && alphabets[j]<=0){
                        j--;
                    }

                    if(j<0){
                        break;
                    }

                    result += (char)(j + 'a');
                    alphabets[j]--;

                    continue; //for adding remainning character of i
                }
            }
            i--;
        }
        return result;
    }
};


int main(){
    Solution obj;
    string s = "aabbcc";
    int repeatLimit = 2;
    cout<<obj.repeatLimitedString(s, repeatLimit)<<endl;
    return 0;
}