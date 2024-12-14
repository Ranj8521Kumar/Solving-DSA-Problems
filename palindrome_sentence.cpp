#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     bool sentencePalindrome(string &s) {
//         // code here
//         int n = s.size();
        
//         int left = 0;
//         int right = n-1;
        
//         while(left <= right){
//             if(isalnum(s[left]) && isalnum(s[right])){
//                 if(tolower(s[left]) != tolower(s[right])){
//                     return false;
//                 }
//                 left++;
//                 right--;
//             }else if(!isalnum(s[left]) && !isalnum(s[right])){
//                 left++;
//                 right--;
//             }else if(!isalnum(s[left])){
//                 left++;
//             }else if(!isalnum(s[right])){
//                 right--;
//             }
//         }
        
//         return true;
//     }
// };

class Solution {
  public:
    bool sentencePalindrome(string &s) {
        // code here
        string temp = "";
        
        int n = s.size();
        
        for(int i = 0; i<n; i++){
            if(isalnum(s[i])){
                temp += tolower(s[i]);
            }
        }
        
        int len = temp.size();
        
        for(int i = 0; i<len/2; i++){
            if(temp[i] != temp[len - i - 1]){
                return false;
            }
        }
        
        return true;
    }
};


//complete the main function
int main(){
    Solution obj;
    string
    s = "A man, a plan, a canal: Panama";
    if(obj.sentencePalindrome(s)) {
        cout << "The sentence is a palindrome." << endl;
    } else {
        cout << "The sentence is not a palindrome." << endl;
    }
    return 0;
}