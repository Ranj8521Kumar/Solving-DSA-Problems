#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int binarySearch(int key, vector<int>& brr) {
        int low = 0, high = brr.size() - 1, mid, index = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (brr[mid] <= key) {
                index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return index;
    }

    long long countPairs(vector<int>& arr, vector<int>& brr) {
        long long one = 0, two = 0, threeFour = 0, ans = 0;
        sort(brr.begin(), brr.end());

        for (auto it : brr) {
            if (it == 1) one++;
            else if (it == 2) two++;
            else if (it == 3 || it == 4) threeFour++;
        }

        for (auto it : arr) {
            if (it != 1) {
                ans += one;
                if (it == 2) ans -= threeFour;
                if (it == 3) ans += two;
                int index = binarySearch(it, brr);
                ans += (brr.size() - index - 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    vector<int> brr = {3, 5, 1, 1};

    cout << sol.countPairs(arr, brr) << endl;

    return 0;
}
