#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int n)
{
    vector<int> result;
    int temp = 1;
    for (int k = 0; k <= n; k++)
    {
        if (k == 0 || k == n)
        {
            result.push_back(1);
        }
        else
        {
            temp = (temp * (n - k + 1)) / k;
            result.push_back(temp);
        }
    }
    return result;
}

int main()
{
    vector<int> result = getRow(5);
    for(auto it: result){
        cout<<it<<" ";
    }
    return 0;
}