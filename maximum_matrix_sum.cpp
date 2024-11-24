#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int minAbsValue = INT_MAX;
        int negCount = 0;
        long long sum = 0;

        for(auto &vec: matrix){
            for(auto it: vec){
                if(it<0){
                    negCount++;
                }
                int absValue = abs(it);
                sum += absValue;
                minAbsValue = min(minAbsValue, absValue);
            }
        }

        if(negCount % 2 == 0){
            return sum;
        }

        return sum - 2*minAbsValue;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    cout<<obj.maxMatrixSum(matrix);
    return 0;
}