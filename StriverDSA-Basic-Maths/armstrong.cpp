#include<bits/stdc++.h>
using namespace std;

bool armstrong(int n){
    int sum = 0;
    int temp = n;
    int k = to_string(n).length();
    while(n>0){
        int lD = n%10;
        sum = sum + pow(lD, k);
        n/=10;
    }
    if(sum== temp){
        return true;
    }else{
    return false;
    }
}

int main()
{
    cout<<armstrong(22074);
    return 0;
}