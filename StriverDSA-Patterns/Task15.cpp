#include <bits/stdc++.h>
using namespace std;

void pattern15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        //character
        char ch= 'A';
        for (int j = n; j >= i; j--)
        {
            cout << ch << " ";
            ch++;
        }
        cout<<endl;  
    }
}

int main()
{
    int n;
    cin >> n;
    pattern15(n);
    return 0;
}