#include<bits/stdc++.h>
using namespace std;

int countDigit(int n){
    int count = 0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}

int main()
{
    cout<<countDigit(22074);
    return 0;
}