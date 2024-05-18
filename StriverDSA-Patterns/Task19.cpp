#include <bits/stdc++.h>
using namespace std;

void pattern19(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*"
                << " ";
        }
        // spaces
        for (int j = 1; j <= 2 * (i - 1); j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*"
                << " ";
        }
        cout << endl;
    }

        for (int i = n; i >= 1; i--)
        {
            // stars
            for (int j = 1; j <= n - i + 1; j++)
            {
                cout << "*"
                    << " ";
            }
            // spaces
            for (int j = 1; j <= 2 * (i - 1); j++)
            {
                cout << " ";
            }
            // stars
            for (int j = 1; j <= n - i + 1; j++)
            {
                cout << "*"
                    << " ";
            }
            cout << endl;
        }
}

    int main()
    {
        int n;
        cin >> n;
        pattern19(n);
        return 0;
    }