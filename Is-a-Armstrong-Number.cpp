#include<bits/stdc++.h>
using namespace std;

bool is_armstrong(int num){
    int original_number=num;
    int n=num;
    int count=0;
    int sum=0;
    while(n!=0){
        n/=10;
        count++;
    }

    while(num!=0){
        int digit=num%10;
        sum=sum+pow(digit,count);
        num/=10;
    }

    if(sum==original_number){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int num=1634;
    if(is_armstrong(num)){
        cout<<num<<" is an Armstrong Number."<<endl;
    }else{
        cout<<num<<" is not an Armstrong Number."<<endl;
    }
    return 0;
}