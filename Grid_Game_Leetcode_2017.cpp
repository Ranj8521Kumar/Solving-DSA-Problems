#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int j = 0; j<n; j++){
            top += grid[0][j];
        }

        long long buttom = 0; long long res = LLONG_MAX;
        for(int j = 0; j<n; j++){
            top -= grid[0][j];//first robot picks from the first row
            res = min(res, max(top, buttom));//minimize the second robot score
            buttom += grid[1][j];//second robot picks from the buttom row
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
    cout<<s.gridGame(grid)<<endl;
    return 0;
}