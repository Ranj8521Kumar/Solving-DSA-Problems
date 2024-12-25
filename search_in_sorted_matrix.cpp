#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Function to search a given number in row-column sorted matrix.
        bool searchMatrix(vector<vector<int>> &mat, int x) {
                int m = mat.size();
                if (m == 0) return false;
                int n = mat[0].size();
                
                int low = 0;
                int high = n * m - 1;
                
                while (low <= high) {
                        int mid = low + (high - low) / 2;
                        
                        int i = mid / n;
                        int j = mid % n;
                        
                        if (mat[i][j] == x) {
                                return true;
                        } else if (mat[i][j] > x) {
                                high = mid - 1;
                        } else {
                                low = mid + 1;
                        }
                }
                
                return false;
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
        
        if (sol.searchMatrix(matrix, target)) {
                cout << "Element found in the matrix." << endl;
        } else {
                cout << "Element not found in the matrix." << endl;
        }
        
        return 0;
}