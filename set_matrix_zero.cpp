#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        bool firstRowHasZero = false;
        bool firstColumnHasZero = false;
        
        //if first column has any zero
        for(int i = 0; i<m; i++){
            if(mat[i][0] == 0){
                firstColumnHasZero = true;
                break;
            }
        }
        
        //if first row has any zero
        for(int j  = 0; j<n; j++){
            if(mat[0][j] == 0){
                firstRowHasZero = true;
                break;
            }
        }
        
        //use first row and  column for markig if any zero found
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(mat[i][j] == 0){
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }
        
        // set all row  and column element zero for marked zero
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        //handle the first row
        if(firstRowHasZero){
            for(int j = 0;  j<n; j++){
                mat[0][j] = 0;
            }
        }
        
        //handle the second row
        if(firstColumnHasZero){
            for(int i = 0; i<m; i++){
                mat[i][0] = 0; 
            }
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    Solution obj;
    obj.setMatrixZeroes(mat);
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}