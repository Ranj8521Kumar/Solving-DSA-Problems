#include<bits/stdc++.h>
using namespace std;

void printN( int i, int n){
    if(i==0){
        return;
    }
    printN(i-1, n);
    cout<<i<<endl;
}

int main()
{
    int n;
    cin>>n;
    printN(n, n);
    return 0;
}