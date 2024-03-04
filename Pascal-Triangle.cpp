// pascal triangle:-
//           1
//         1   1
//        1  2   1
//       1  3  3  1
//      1 4  6  4  1 and so on...

// first row(n=0):- 0c0
// second row(n=1):- 1c0 1c1
// third row(n=2):- 2c0 2c1 2c2
// fourth roe(n=3):- 3c0 3c1 3c2 3c3
// and so on...

// ncr=((nc(r-1))*(n-r+1))/r

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generatePascalTriangle(int numRows)
    {
        vector<vector<int>> pascalTriangle;
        for (int n = 0; n < numRows; n++)
        {
            vector<int> currentRow;
            int temp = 1; // 0c0
            currentRow.push_back(temp);

            for (int r = 1; r <= n; r++)
            {
                temp = (temp * (n - r + 1)) / r;
                currentRow.push_back(temp);
            }
            pascalTriangle.push_back(currentRow);
        }
        return pascalTriangle;
    }

    void printPascalTriangle(const vector<vector<int>> &triangle)
    {
        int numRows = triangle.size();
        for (int i = 0; i < numRows; i++)
        {
            int numSpaces = numRows - i - 1;
            for (int j = 0; j < numSpaces; j++)
            {
                cout << " ";
            }

            for (int j = 0; j <= i; j++)
            {
                cout << triangle[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    int numRows = 6;
    Solution obj;
    vector<vector<int>> triangle = obj.generatePascalTriangle(numRows);
    obj.printPascalTriangle(triangle);
    return 0;
}