#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        
        for(int i = 0; i < arr.size(); i++) {
            if(mpp.find(arr[i]) != mpp.end() && i - mpp[arr[i]] <= k) {
                return true;
            }
            mpp[arr[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 1, 4, 5};
    int k = 3;

    if(solution.checkDuplicatesWithinK(arr, k)) {
        cout << "Duplicates found within range " << k << endl;
    } else {
        cout << "No duplicates found within range " << k << endl;
    }

    return 0;
}
