#include<bits/stdc++.h>
using namespace std;

// vector<int> defuseTheBomb(vector<int>& code, int k) {
//     int n = code.size();
//     vector<int> res(n, 0);
//     if(k == 0){
//         return res;
//     }
//     for(int i = 0; i < n; i++){
//         if(k > 0){
//             for(int j = 1; j <= k; j++){
//                 res[i] += code[(i+j)%n];
//             }
//         }else{
//             for(int j = 1; j <= abs(k); j++){
//                 res[i] += code[(i-j+n)%n];
//             }
//         }
//     }
//     return res;
// }

    vector<int> defuseTheBomb(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result(n, 0); 
        if(k == 0){
            return result;
        }else if(k>0){
            for(int i = 0; i<n; i++){
                int sum =  0;
                int j =  i+1;
                int count = k;
                while(count--){
                    sum += arr[j%n];
                    j++;
                }
                result[i] = sum;
            }
        }else{
            for(int i = 0; i<n; i++){
                int sum =  0;
                int j =  i-1;
                int count = -k;
                while(count--){
                    sum += arr[(j+n)%n];
                    j--;
                }
                result[i] = sum;
            }
        }
        return result;
    }

// main function
int main(){
    vector<int> code = {5,7,1,4};
    int k = 3;
    vector<int> res = defuseTheBomb(code, k);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}