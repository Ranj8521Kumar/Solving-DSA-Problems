#include<bits/stdc++.h>
using namespace std;

// //wriete Brute force Approach
// class Solution {
//   public:
//     int countPairs(vector<int> &arr, int target) {
//         // Code here
//         int n = arr.size();
//         int result = 0;
        
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 if((arr[i] + arr[j]) == target){
//                     result++;
//                 }
//             }
//         }
        
//         return result;
//     }
// };


//Optimal Approach
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int, int> mpp;
        int result = 0;
        
        for(auto &it: arr){
            if(mpp.count(target - it) > 0){
                result += mpp[target - it];
            }
            
            mpp[it]++;
        }
        
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 5, 7, 1};
    Solution obj;
    cout<<obj.countPairs(nums, 6);
    return 0;
}