#include<bits/stdc++.h>
using namespace std;

void is_odd_or_even(int num){
    if(num%2==0){
        cout<<num<<" is an even Number."<<endl;
    }else{
        cout<<num<<" is an odd Number."<<endl;
    }
}

int main()
{
    int num=8;
    is_odd_or_even(num);
    return 0;
}