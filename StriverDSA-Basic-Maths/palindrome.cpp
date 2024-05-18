#include<bits/stdc++.h>
using namespace std;

int palindromeNumber(int n){
    int rev = 0;
    int temp = n;
    while(n>0){
        int lastDigit = n%10;
        rev = (rev*10)+lastDigit;
        n/=10;
    }
    if(temp==rev){
        return true;
    }else{
        return false;
    }
}

int main()
{
    cout<<palindromeNumber(22074);
    return 0;
}