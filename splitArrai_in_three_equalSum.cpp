#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        if(totalSum % 3 != 0) {
            return {-1, -1};
        }

        int splitSum = totalSum / 3;
        int currSum = 0; 
        vector<int> result;

        for(int i = 0; i < n; i++) {
            currSum += arr[i];
            if(currSum == splitSum) {
                result.push_back(i);
                currSum = 0;
            }
            
            if(result.size() == 2) {
                break;
            }
        }

        if(result.size() == 2) {
            return result;
        }

        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 0, 3};
    vector<int> result = sol.findSplit(arr);

    if(result[0] != -1 && result[1] != -1) {
        cout << "Split points at indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "Cannot split array into three equal sum parts." << endl;
    }

    return 0;
}
