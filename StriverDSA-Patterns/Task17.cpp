#include <bits/stdc++.h>
using namespace std;

void pattern17(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch= 'A';
        //space
        for (int j = 1; j <= n-i; j++)
        {
            cout <<" ";
        }

        //character
        for (int j = 1; j <= 2*i-1; j++)
        {
            if(j<=(2*i-1)/2){
                cout <<ch<<" ";
                ch++;
            }else{
                cout <<ch<<" ";
                ch--;
            }
        }

        //space
        for (int j = 1; j <= n-i; j++)
        {
            cout <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    pattern17(n);
    return 0;
}