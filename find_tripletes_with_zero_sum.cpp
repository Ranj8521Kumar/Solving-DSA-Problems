#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Brute force Approach
// User function Template for C++
class Solution {
  public:
  //Brute Force Code
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if((arr[i] + arr[j] + arr[k]) == 0){
                        result.push_back({i, j, k});
                    }
                }
            }
        }
        
        return result;
    }
};

//first optimal Approach
class Solution {
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> result;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicates
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == 0) {
                    result.push_back({arr[i], arr[left], arr[right]});
                    while (left < right && arr[left] == arr[left + 1]) left++; // Skip duplicates
                    while (left < right && arr[right] == arr[right - 1]) right--; // Skip duplicates
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

//second optimal Approach
class Solution {
  public:
  //Optimized Code
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++){
            mpp[arr[i]].push_back(i);
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
               int sum = -(arr[i] + arr[j]);
               if(mpp.find(sum) != mpp.end()){
                   for(auto &k: mpp[sum]){
                       if(k > j){
                           result.push_back({i, j, k});
                       }
                   }
               }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = sol.findTriplets(arr);
    
    for (const auto &triplet : triplets) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}