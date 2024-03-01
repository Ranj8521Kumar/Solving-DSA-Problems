#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=12345;
    int num=n;
    int reverse=0;
    while (num!=0)
    {
        int digit=num%10;
        reverse=reverse*10+digit;
        num/=10;
    }
    
    cout<<"The Reverse of the number "<<n<<" is "<<reverse<<endl;
    return 0;
}