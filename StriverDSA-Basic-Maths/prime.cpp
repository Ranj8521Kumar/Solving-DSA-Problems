#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0){
            count = count + 1;
            if(n/i!=i){
                count = count +1;
            }
        }
    }
    if(count==2){
        return true;
    }else{
        return false;
    } 
}

int main()
{
    cout<<(prime(2)?"true":"false");
    return 0;
}