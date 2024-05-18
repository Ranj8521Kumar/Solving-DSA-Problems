#include<bits/stdc++.h>
using namespace std;

void printName(int n){
    if(n==0){
        return;
    }
    printName(n-1);
    cout<<"Ranjan"<<endl;
}

int main()
{
    int n;
    cin>>n;
    printName(n);
    return 0;
}