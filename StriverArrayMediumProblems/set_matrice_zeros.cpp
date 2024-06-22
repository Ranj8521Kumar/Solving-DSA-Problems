#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowHasZero = false;
        bool firstColumnHasZero = false;

        // Check if the first column has any zeros
        for(int i = 0; i<m; i++){
            if(matrix[i][0]==0){
                firstColumnHasZero = true;
                break;
            }
        }
        
        // Check if the first row has any zeros
        for(int j = 0; j<n; j++){
            if(matrix[0][j]==0){
                firstRowHasZero = true;
                break;
            }
        }

        // Use the first row and column to mark zeros
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // Zero out rows based on markers in the first column
        for(int i = 1; i<m; i++){
            if(matrix[i][0]==0){
                for(int j = 0; j<n; j++){
                    matrix[i][j]=0;
                }
            }
        }


        // Zero out columns based on markers in the first row
        for(int j =1; j<n; j++){
            if(matrix[0][j]==0){
                for(int i = 0; i<m; i++){
                    matrix[i][j]=0;
                }
            }
        }
        
        //zero out the first row if needed
        if(firstRowHasZero){
            for(int j = 0; j<n; j++){
                matrix[0][j]=0;
            }
        }


        //zero out the first column if needed
        if(firstColumnHasZero){
            for(int i = 0; i<m; i++){
                matrix[i][0]=0;
            }
        }
    }

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,0,6},{7,8,9}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}