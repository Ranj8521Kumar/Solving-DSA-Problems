#include<bits/stdc++.h>
using namespace std;

bool is_Prime(int num){
    for (int i = 2; i < num; i++)
    {
        if(num%i==0){
            return false;
        }else{
            return true;
        }
    }
    
}

int main()
{
    int num=17;
    if(is_Prime(num)){
        cout<<num<<" is a Prime Number."<<endl;
    }else{
        cout<<num<<" is not a Prime Number."<<endl;
    }
    return 0;
}