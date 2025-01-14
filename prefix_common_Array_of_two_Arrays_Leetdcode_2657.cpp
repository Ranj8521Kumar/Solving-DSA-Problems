#include<bits/stdc++.h>
using namespace std;

// //Brute Force Approach
// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();

//         unordered_set<int> st1;
//         unordered_set<int> st2;

//         vector<int> result;

//         int count = 0;
//         for(int i = 0; i<n; i++){
//             st1.insert(A[i]);
//             st2.insert(B[i]);

//             for(int j = 0; j<=i; j++){
//                 if(st1.find(A[j]) != st1.end() && st2.find(A[j]) != st2.end()){
//                     count++;
//                 }
//             }

//             result.push_back(count);
//             count = 0;
//         }

//         return result;
//     }
// };

// //or

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();

//         unordered_set<int> st1;
//         unordered_set<int> st2;

//         vector<int> result;

//         int count = 0;
//         for(int i = 0; i<n; i++){
//             st1.insert(A[i]);
//             st2.insert(B[i]);

//             for(int j = 0; j<=i; j++){
//                 if(st1.count(A[j]) && st2.count(A[j])){
//                     count++;
//                 }
//             }

//             result.push_back(count);
//             count = 0;
//         }

//         return result;
//     }
// };

//Optimal Approach
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        unordered_set<int> seen;

        vector<int> result;

        int count = 0;
        for(int i = 0; i<n; i++){
            if(seen.count(A[i])){
                count++;
            }else{
                seen.insert(A[i]);
            }

            if(seen.count(B[i])){
                count++;
            }else{
                seen.insert(B[i]);
            }

            result.push_back(count);
        }

        return result;
    }
};

int main(){
    Solution obj;
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {1, 2, 3, 4};
    vector<int> result = obj.findThePrefixCommonArray(A, B);

    for(auto &x: result){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}