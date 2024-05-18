#include<bits/stdc++.h>
using namespace std;

void pattern6(int n){
    
    for (int i = 1; i <= n; i++)
    {
        int number=1;
        {
            for (int j = 1; j <=n-i+1; j++)
            {
                cout<<number<<" ";
                number+=1;
            }
            cout<<endl;
            
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    pattern6(n);
    return 0;
}