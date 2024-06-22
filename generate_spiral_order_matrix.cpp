#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int A)
{
    int left = 0;
    int top = 0;
    int right = A - 1;
    int buttom = A - 1;
    vector<vector<int>> result(A, vector<int>(A, 0));
    int num = 1;

    while (top <= buttom && left <= right && num <= pow(A, 2))
    {
        for (int j = left; j <= right; j++)
        {
            result[top][j] = num;
            num++;
        }
        top++;

        for (int i = top; i <= buttom; i++)
        {
            result[i][right] = num;
            num++;
        }
        right--;

        if (top <= buttom)
        {
            for (int j = right; j >= left; j--)
            {
                result[buttom][j] = num;
                num++;
            }
            buttom--;
        }

        if (left <= right)
        {
            for (int i = buttom; i >= top; i--)
            {
                result[i][left] = num;
                num++;
            }
            left++;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> result = generateMatrix(5);

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