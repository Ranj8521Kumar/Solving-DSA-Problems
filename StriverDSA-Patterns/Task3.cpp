#include<bits/stdc++.h>
using namespace std;

void pattern3(int n){
    
    for (int i = 1; i <= n; i++)
    {
        int number=1;
        {
            for (int j = 1; j <=i; j++)
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
    pattern3(n);
    return 0;
}