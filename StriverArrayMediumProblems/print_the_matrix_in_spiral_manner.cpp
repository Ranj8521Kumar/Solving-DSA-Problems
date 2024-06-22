#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int top = 0;
    int buttom = m - 1;
    int left = 0;
    int right = n - 1;

    vector<int> result;

    while (top <= buttom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }
        top++;

        for (int i = top; i <= buttom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= buttom)
        {
            for (int j = right; j >= left; j--)
            {
                result.push_back(matrix[buttom][j]);
            }
            buttom--;

            if (left <= right)
            {
                for (int i = buttom; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,0,6},{7,8,9}};
    vector<int> result = spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
            cout<<result[i]<<" ";
    }
    
    return 0;
}