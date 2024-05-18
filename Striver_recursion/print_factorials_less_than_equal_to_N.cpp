#include<bits/stdc++.h>
using namespace std;

    vector<long long> factorialNumbers(long long N)
    {
        vector<long long> result;
            int i = 1;
            long long factorial = 1;
            
            while(true){
                factorial = factorial * i;
                if(factorial > N){
                    break;
                }
                result.push_back(factorial);
                i++;
            }
            return result;
    }

int main()
{
    int n;
    cin>>n;
    factorialNumbers(n);
    return 0;
}