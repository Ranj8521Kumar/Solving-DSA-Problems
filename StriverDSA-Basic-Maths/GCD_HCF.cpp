#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a>b){
        a%=b;
    }else{
        b%=a;
    }
    if(a==0){
        return b;
    }
    else{
        return a;
    }
}

int main()
{
    cout<<gcd(4,8);
    return 0;
}