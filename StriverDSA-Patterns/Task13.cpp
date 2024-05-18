#include <bits/stdc++.h>
using namespace std;

void pattern13(int n)
{
    int num= 1;
    for (int i = 1; i <= n; i++)
    {
        //num
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout<<endl;  
    }
}

int main()
{
    int n;
    cin >> n;
    pattern13(n);
    return 0;
}