#include<bits/stdc++.h>
using namespace std;

void recursion(int n){
    if(n<1){
        return;
    }else
    {
        cout<<n<<endl;
        n--;
        recursion(n);
    }
    
}

int main()
{
    int n=10;
    recursion(10);
    return 0;
}