#include <bits/stdc++.h>
using namespace std;

void pattern11(int n)
{
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            num = 1;
        }
        else
        {
            num = 0;
        }
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = 1 - num;
        }
      cout<<endl;  
    }
}

int main()
{
    int n;
    cin >> n;
    pattern11(n);
    return 0;
}