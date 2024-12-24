#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        int count = 0;
        
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mpp;
        
        for(int i = 0; i<n; i++){
            mpp[sorted[i]] = i;
        }
        
        for(int i = 0; i<n; ){
            int correctIndex = mpp[arr[i]];
            
            if(i != correctIndex){
                swap(arr[correctIndex], arr[i]);
                count++;
            }else{
                i++;
            }
        }
        
        return count;
    }
};

// more optimized solution than the previous one


class Solution {
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Pair elements with their indices and sort by value
        vector<pair<int, int>> sorted(n);
        for(int i = 0; i<n; i++){
            sorted[i] = {arr[i], i};
        }
        sort(sorted.begin(), sorted.end());

        // Use the array itself to detect and resolve cycles
        for (int i = 0; i < n; i++) {
            // Skip if already in the correct position or visited (cycle resolved)
            while(sorted[i].second != i){
                int correctIndex = sorted[i].second;
                swap(sorted[i], sorted[correctIndex]);
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum number of swaps required to sort the array: " << sol.minSwaps(arr) << endl;
    return 0;
}