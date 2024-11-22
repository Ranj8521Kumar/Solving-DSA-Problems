#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxRows = 0;

        unordered_map<string, int> mpp;

        for(vector<int>& row: matrix){
            string pattern = "";
            string complement = "";

            for(auto cell: row){
                pattern += (cell==0)?'0':'1';
                complement += (cell==0)?'1':'0';
            }

            mpp[pattern]++;
            mpp[complement]++;
        }
        
        for(auto &[pattern, count]: mpp){
            maxRows = max(maxRows, count);
        }
        
        return maxRows;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {{0, 1}, {1, 1}, {0, 1}, {1, 0}};
    cout<<obj.maxEqualRowsAfterFlips(matrix)<<endl;
    return 0;
}