#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Binary Search function
    bool binarySearch(vector<int>& row, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (row[mid] == target) {
                return true;
            } else if (row[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false; // Return false if target is not found
    }

    // Function to search a given number in a row-column sorted matrix
    bool searchRowMatrix(vector<vector<int>>& mat, int x) {
        int m = mat.size();
        int n = mat[0].size();

        for (auto& row : mat) {
            if (x >= row[0] && x <= row[n - 1]) {
                if(binarySearch(row, 0, n - 1, x)){
                    return true;
                }
            }
        }

        return false; // Return false if target is not found in any row
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (sol.searchRowMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}