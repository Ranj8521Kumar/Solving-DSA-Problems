#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
            {0, 1}, // East
            {1, 0}, // South
            {0, -1}, // West
            {-1, 0} // North
        };

        vector<vector<int>> result;
        result.push_back({rStart, cStart}); // Start position

        int steps = 0; // Number of steps to move in the current direction
        int dir = 0; // Index to track the direction

        while (result.size() < rows * cols) {
            // Increase steps every two directions (East or West)
            if (dir == 0 || dir == 2) {
                steps++;
            }

            // Move in the current direction
            for (int count = 0; count < steps; count++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                // Check if the new position is within bounds
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                }
            }
            // Change direction
            dir = (dir + 1) % 4;
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> result1 = solution.spiralMatrixIII(1, 4, 0, 0);
    cout << "Spiral matrix for 1x4 grid starting at (0, 0):" << endl;
    for (const auto& coord : result1) {
        cout << "[" << coord[0] << "," << coord[1] << "] ";
    }
    cout << endl;

    return 0;
}
