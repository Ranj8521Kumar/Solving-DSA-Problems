#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        int maxElem = *max_element(arr.begin(), arr.end());
        vector<int> mpp(maxElem + 1, 0);
        
        for (int num : arr) {
            mpp[num]++;
        }
        
        for (int i = 0; i <= maxElem; ++i) {
            if (mpp[i] > 0) {
                k -= mpp[i];
                if (k <= 0) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    Solution sol;
    int result = sol.kthSmallest(arr, k);
    
    if (result != -1) {
        cout << "The " << k << "-th smallest element is " << result << endl;
    } else {
        cout << "The " << k << "-th smallest element does not exist." << endl;
    }
    
    return 0;
}
