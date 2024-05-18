#include<bits/stdc++.h>
using namespace std;

void pattern10(int n){
    
    for (int i = 1; i <= 2*n-1; i++)
    {
        if(i<=n){
            for (int j = 1; j <=i; j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }else{
            for (int j = 1; j <= 2*n-i; j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        
    }
    
}

int main()
{
    int n;
    cin>>n;
    pattern10(n);
    return 0;
}