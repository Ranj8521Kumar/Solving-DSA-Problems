#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;
        int n = arr.size();

        for (const auto& str : arr) {
            mpp[str]++;
        }

        for (const auto& str : arr) {
            if (mpp[str] == 1) {
                k--;
                if (k == 0) {
                    return str;
                }
            }
        }

        return "";
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"a", "b", "a", "c", "b", "d", "c", "e"};
    int k = 2;
    cout << "The " << k << "-th distinct string is: " << sol.kthDistinct(arr, k) << endl;

    return 0;
}
