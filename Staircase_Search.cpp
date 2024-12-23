#include<bits/stdc++.h>
using namespace std;

//matrix is sorted in row and column wise then we can apply staicase search algorithm
class Solution{
    public:
    bool staircaseSearch(vector<vector<int>> &matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;

        while(i < m  && j >= 0){
            int current = matrix[i][j];
            if(current ==  target){
                return true;
            }else if(current > target){
                j--;
            }else{
                i++;
            }
        }

        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    Solution s;
    cout<<s.staircaseSearch(matrix, 5)<<endl;
    cout<<s.staircaseSearch(matrix, 20)<<endl;
    return 0;
}