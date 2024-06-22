#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int A)
{
    vector<int> result;

    if (A < 2)
    {
        return result;
    }

    vector<bool> isPrime(A + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= A; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= A; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= A; i++)
    {
        if (isPrime[i])
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    vector<int> result = sieve(10);
    for(int it: result){
        cout<<it<<" ";
    }
    return 0;
}