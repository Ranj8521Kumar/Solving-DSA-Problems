#include <bits/stdc++.h>
using namespace std;

void pattern21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= n; j++)
        {
            if(i==1 || i==n || j==1 || j==n){
            cout << "*";
                }else{
                    cout<<" ";
                }
        }
        cout<<endl;
        }
    }
    
    int main()
    {
        int n;
        cin >> n;
        pattern21(n);
        return 0;
    }