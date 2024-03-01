#include<bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2){
    int gcd;
    for (int i = 1; i <=min(num1, num2); i++)
    {
        if(num1%i==0&&num2%i==0){
            gcd=i;
        }
    }
    
    return gcd;

}

int main()
{
    int num1=8, num2=12;
    cout<<"GCD of "<<num1<<" and "<<num2<<" is "<<gcd(num1,num2);
    return 0;
}