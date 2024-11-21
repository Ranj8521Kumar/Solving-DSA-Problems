#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void markGuarded(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        //up
        for(int i = row - 1; i>=0; i--){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }

            grid[i][col] = 1;
        }

        //down
        for(int i = row + 1; i<m; i++){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }

            grid[i][col] = 1;
        }

        //left
        for(int j = col - 1; j>=0; j--){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }

            grid[row][j] = 1;
        }

        //right
        for(int j = col + 1; j<n; j++){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }

            grid[row][j] = 1;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));

        //for guarded->1; for guard->2 and for wall->3
        for(vector<int> &vec: guards){
            int i = vec[0];
            int j = vec[1];

            grid[i][j] = 2;
        }

        for(vector<int> &vec: walls){
            int i = vec[0];
            int j = vec[1];

            grid[i][j] = 3;
        }

        for(vector<int>& vec: guards){
            int i = vec[0];
            int j  = vec[1];

            markGuarded(i, j, grid);
        }

        int count = 0;
        for(int i  = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> guards = {{0, 0}, {0, 1}};
    vector<vector<int>> walls = {{0, 2}};
    cout << obj.countUnguarded(1, 3, guards, walls) << endl;
    return 0;
}