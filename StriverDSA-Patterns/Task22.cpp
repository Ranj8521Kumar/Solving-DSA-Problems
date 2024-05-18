#include <bits/stdc++.h>
using namespace std;

void pattern22(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            int top = i-1;
            int buttom = 2*n - i -1;
            int left = j - 1;
            int right = 2*n - j -1;
            cout<<n - min(min(top, buttom) , min(left, right))<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    pattern22(n);
    return 0;
}