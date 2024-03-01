#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int n){
    int reverse=0;
    int num=n;
    while(num!=0){
        int digit=num%10;
        reverse=reverse*10+digit;
        num/=10;
    }

    if(reverse==n){
        return true;
    }else{
        return false;
    }
}


int main()
{
    int num=12321;
    is_palindrome(num)?cout<<"The "<<num<<" is a Palindrome Number.":cout<<"The "<<num<<" is a Palindrome Number.";
    return 0;
}