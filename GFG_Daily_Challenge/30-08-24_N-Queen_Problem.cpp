#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<int>& queens) {
        for (int i = 0; i < col; ++i) {
            int placed_row = queens[i];
            if (placed_row == row || abs(placed_row - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }
    
    void solveNQueens(int col, int n, vector<int>& queens, vector<vector<int>>& solutions) {
        if (col == n) {
            solutions.push_back(queens);
            return;
        }
        
        for (int row = 1; row <= n; ++row) {
            if (isSafe(row, col, queens)) {
                queens[col] = row;
                solveNQueens(col + 1, n, queens, solutions);
                queens[col] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> queens(n, 0);
        solveNQueens(0, n, queens, solutions);
        return solutions;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    Solution sol;
    vector<vector<int>> results = sol.nQueen(n);
    
    cout << "The distinct solutions are:" << endl;
    for (auto& solution : results) {
        for (int queen : solution) {
            cout << queen << " ";
        }
        cout << endl;
    }
    
    return 0;
}
