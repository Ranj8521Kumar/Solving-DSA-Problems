#include<bits/stdc++.h>
using namespace std;

int count(int num){
    int count=0;
    while (num!=0)
    {
        num/=10;
        count++;
    }
    return count;
}

int main()
{
    int n=123456;
    cout<<"Number of Digits in "<<n<<" is "<<count(n)<<endl;
    return 0;
}