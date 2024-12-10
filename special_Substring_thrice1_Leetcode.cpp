#include<bits/stdc++.h> 
using namespace std;

//Brute force solution:
class Solution {
private:
    bool check(string str){
        int n = str.size();
        for(int i = 1; i<n; i++){
            if(str[i-1] != str[i]){
                return 0;
            }
        }
        return 1;
    }

public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> mpp;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                mpp[s.substr(i, j - i + 1)]++;
            }
        }

        int maxSpecSubString  = -1;
        for(auto &str: mpp){
            if(str.second >= 3 && check(str.first)){
                int n = str.first.size();
                maxSpecSubString = max(maxSpecSubString, n);
            }
        }

        return maxSpecSubString;
    }
};

//optimized solution:
// class Solution {
// private:
//     bool check(string str){
//         int n = str.size();
//         for(int i = 1; i<n; i++){
//             if(str[i-1] != str[i]){
//                 return 0;
//             }
//         }
//         return 1;
//     }

//     bool canFindSpecialSubString(string str, int len){
//         unordered_map<string, int> mpp;

//         int n  = str.size();

//         for(int i = 0; i<=n-len; i++){
//             string sub = str.substr(i, len);

//             if(check(sub)){
//                 mpp[sub]++;
//                 if(mpp[sub]>=3){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// public:
//     int maximumLength(string s) {
//         int n = s.size();

//         int result = -1;

//         int left = 1;
//         int right = s.size();

//         while(left<=right){
//             int mid = left + (right - left)/2;

//             if(canFindSpecialSubString(s, mid)){
//                 result = mid;
//                 left = mid+1;
//             }else{
//                 right = mid-1;
//             }
//         }
//         return result;
//     }
// };

int main() {
    Solution obj;
    string s = "abc";
    cout << obj.maximumLength(s) << endl;
    return 0;
}