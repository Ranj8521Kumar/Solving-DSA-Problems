#include <bits/stdc++.h>
using namespace std;

void pattern16(int n)
{
    char ch= 'A';
    for (int i = 1; i <= n; i++)
    {
        //character
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout<<endl; 
        ch++; 
    }
}

int main()
{
    int n;
    cin >> n;
    pattern16(n);
    return 0;
}