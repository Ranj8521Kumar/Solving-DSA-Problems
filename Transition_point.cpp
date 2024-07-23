#include <iostream>

class Solution
{
public:    
    int transitionPoint(int arr[], int n) {
        int ans = -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == 1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int arr1[] = {0, 0, 0, 1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int transition1 = sol.transitionPoint(arr1, n1);
    std::cout << "Transition point index in arr1: " << transition1 << std::endl;
    
    return 0;
}
