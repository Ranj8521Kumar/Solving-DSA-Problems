#include<bits/stdc++.h>
using namespace std;
long long tittleToNumber(string &str){
    long long result  = 0;
    for(char ch : str){
        result = result*26 + (ch - 'A' + 1);
    }
    return result;
}

int main()
{
    // string str = "ABED";
    string str = "COD";
    cout<<tittleToNumber(str);
    return 0;
}