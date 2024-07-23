#include<bits/stdc++.h>
using namespace std;

//Use the Sieve of Eratosthenes to generate all prime numbers up to A

vector<int> primeSum(int A){
    vector<bool> is_prime(A+1, true);
    is_prime[0] = is_prime[1] = false;


    for(int i = 2; i<= sqrt(A); i++){
        if(is_prime[i]){
            for(int j = i*i; j<=A; j = j+i){
                is_prime[j] = false;
            }
        }
    }

    //Iterate through these primes to find a pair whose sum equals A, ensuring we return the lexicographically smallest pair.

    for(int i = 2; i<=A; i++){
        if(is_prime[i] && is_prime[A-i]){
            return {i, A-i};
        }
    }
}

int main()
{
    int A = 4; 
    vector<int> result = primeSum(A);
    for(auto it: result){
        cout<<it<<" ";
    }
    return 0;
}