#include <bits/stdc++.h>
using namespace std;

void pattern20(int n)
{
    for (int i = 1; i <= 2*n-1; i++)
    {
        if(i<=n){
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                << " ";
        }
        // spaces
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                << " ";
        }
        cout << endl;
        }else{
            for (int j = 1; j <= 2*n - i; j++)
        {
            cout << "*"
                << " ";
        }
        // spaces
        for (int j = 1; j <= i-(2*n - i); j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= 2*n - i; j++)
        {
            cout << "*"
                << " ";
        }
        cout << endl;
        }
    }
}

    int main()
    {
        int n;
        cin >> n;
        pattern20(n);
        return 0;
    }