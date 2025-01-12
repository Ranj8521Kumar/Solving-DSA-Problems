#include<bits/stdc++.h>
using namespace std;

//first approach
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n%2 != 0) return false;

        int open = 0; int unlocked = 0;
        for(int i = 0; i<n; i++){
            if(locked[i] == '0'){
                unlocked++;
            }else if(s[i] == '('){
                open++;
            }else{
                if(open > 0){
                    open--;
                }else if(unlocked > 0){
                    unlocked--;
                }else{
                    return false;
                }
            }
        }

        int close = 0;
        unlocked = 0;
        for(int i = n-1; i>=0; i--){
            if(locked[i] == '0'){
                unlocked++;
            }else  if(s[i] == ')'){
                close++;
            }else{
                if(close > 0){
                    close--;
                }else if(unlocked > 0){
                    unlocked--;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};

//second approach
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n%2 != 0) return false;

        stack<int> openIndices;
        stack<int> unlockedIndices;

        for(int i = 0; i<n; i++){
            if(locked[i] == '0'){
                unlockedIndices.push(i);
            }else if(s[i] == '('){
                openIndices.push(i);
            }else{
                if(!openIndices.empty()){
                    openIndices.pop();
                }else if(!unlockedIndices.empty()){
                    unlockedIndices.pop();
                }else{
                    return false;
                }
            }
        }

        while(!openIndices.empty() && !unlockedIndices.empty() && openIndices.top() < unlockedIndices.top()){
            openIndices.pop();
            unlockedIndices.pop();
        }

        if(openIndices.empty() && !unlockedIndices.empty()){
            if(unlockedIndices.size() % 2 != 0){
                return false;
            }else{
                return true;
            }
        }

        return openIndices.empty();
    }
};

int main(){
    Solution s;
    cout<<s.canBeValid("((()))", "000000")<<endl;
    cout<<s.canBeValid("((()))", "111111")<<endl;
    cout<<s.canBeValid("((()))", "010101")<<endl;
    cout<<s.canBeValid("((()))", "101010")<<endl;
    cout<<s.canBeValid("((()))", "110011")<<endl;
    cout<<s.canBeValid("((()))", "011001")<<endl;
    cout<<s.canBeValid("((()))", "100110")<<endl;
    cout<<s.canBeValid("((()))", "001100")<<endl;
    cout<<s.canBeValid("((()))", "101100")<<endl;
    cout<<s.canBeValid("((()))", "100101")<<endl;
    cout<<s.canBeValid("((()))", "010010")<<endl;
    cout<<s.canBeValid("((()))", "001001")<<endl;
    cout<<s.canBeValid("((()))", "110110")<<endl;
    cout<<s.canBeValid("((()))", "000001")<<endl;
    cout<<s.canBeValid("((()))", "111111")<<endl;

    return 0;
}