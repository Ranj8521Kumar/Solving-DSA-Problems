#include<bits/stdc++.h>
using namespace std;

// Return 1 if A is prime, else 0
int isPrime(int A) {
	
	if(A<=1){
		return 0;
	}
	
	for (int i = 2; i < A; i++) {
		if ( A % i == 0) return 0;
	}
	return 1;
}


int main()
{
    cout<<isPrime(3);
    return 0;
}