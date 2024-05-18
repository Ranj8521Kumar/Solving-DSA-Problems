#include<bits/stdc++.h>
using namespace std;

int fibbonacci(int num){
        if(num==1||num==2){
                return 1;
        }
        return fibbonacci(num-1)+ fibbonacci(num-2);
}

int main()
{
        int n;
        cin>>n;
        cout<<fibbonacci(n);
}