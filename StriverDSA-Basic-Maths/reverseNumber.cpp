#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n){
    int rev = 0;
    while(n>0){
        int lastDigit = n%10;
        rev = (rev*10)+lastDigit;
        n/=10;
    }
    return rev;
}

int main()
{
    cout<<reverseNumber(22074);
    return 0;
}