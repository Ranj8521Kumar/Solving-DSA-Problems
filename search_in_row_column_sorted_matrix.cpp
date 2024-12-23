#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int m = mat.size();
        int n = mat[0].size();
        
        // to acheive O(m + n) time complexity even in worst case
        
        int i = 0;
        int j = n-1;
        
        while(i < m && j >= 0){
            int current = mat[i][j];
            if(current == x){
                return true;
            }else if(current > x){
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
    cout<<s.matSearch(matrix, 5)<<endl;
    cout<<s.matSearch(matrix, 20)<<endl;
    return 0;
}