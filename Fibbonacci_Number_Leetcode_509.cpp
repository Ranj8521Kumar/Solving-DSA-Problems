#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }

        return fib(n-1) + fib(n-2);
    }
};

class Solution {
public:
//using dp
    int solve(int n, vector<int>& dp){
        if(n <= 1){
            return n;
        }

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int fib(int n) {
        if(n <= 1){
            return n;
        }

        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};

class Solution {
public:
//using buttom-up approach
    int fib(int n) {
        if(n<=1) return n;

        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


class Solution {
public:
//using buttom-up approach with constant space complexity
    int fib(int n) {
        if(n <= 1) return n;

        int a = 0; 
        int b = 1;

        int c;

        //total number of iteration equal to (n-1)
        for(int i = 1; i<n; i++){
            c = a+b;
            a = b;
            b = c;
        }

        return c;
    }
};

int main() {
    Solution solution;
    int n = 10; // Example input
    std::cout << "Fibonacci of " << n << " is " << solution.fib(n) << std::endl;
    return 0;
}