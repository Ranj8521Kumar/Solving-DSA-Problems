#include<bits/stdc++.h>
using namespace std;

// long long sumOfSeries(long long n) {
//         //long long sum = pow((n*(n+1))/2, 2);
//         long long sum =((n*(n+1))/2)*((n*(n+1))/2);
//         return sum;
//     }

long long sumOfSeries(long long n) {
        if(n==0){
            return 0;
        }
        return pow(n, 3)+sumOfSeries(n-1);
    }

int main()
{
    long long n;
    cin>>n;
    cout<<sumOfSeries(n);
    return 0;
}