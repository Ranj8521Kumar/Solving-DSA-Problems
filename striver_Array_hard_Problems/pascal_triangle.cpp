#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        for(int n = 0; n<numRows; n++){
            int temp = 1; //nC0
            vector<int> currentRow;
            currentRow.push_back(temp);

            for(int r = 1; r <= n; r++){
                temp = (temp * (n-r+1))/r;
                currentRow.push_back(temp);
            }

            pascalTriangle.push_back(currentRow);
        }
        return pascalTriangle;
    }

int main()
{
    vector<vector<int>> result = generate(5);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;  
    }
    
    return 0;
}