#include<bits/stdc++.h>
using namespace std;

void divisors(int n){
    vector<int> divs;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0){
            divs.push_back(i);
            if(n/i!=i){
                divs.push_back(n/i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    for (auto it : divs){
        cout<<it<<" ";
    }  
}

int main()
{
    divisors(36);
    return 0;
}