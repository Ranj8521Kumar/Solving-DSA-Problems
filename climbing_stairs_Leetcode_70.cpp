#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    //Brute force
    int solve(int n){
        if(n < 0){
            return 0;
        }

        if(n == 0){
            return 1;
        }

        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return one_step + two_step;
    }

    int climbStairs(int n) {

        return solve(n);
    }
};


class Solution {
public:
// using buttom up approach with constant space complexity
    int solve(int n, vector<int>& arr){
        if(n < 0){
            return 0;
        }

        if(n <= 2){
            return n;
        }

        int a = 1; // i - 2
        int b = 2; // i - 1
        int c;
        for(int i = 3; i<=n; i++){
            c = a + b;

            a = b;
            b = c;
        }

        return c;
    }

    int climbStairs(int n) {
        vector<int> arr(n+1, -1);
    
        return solve(n, arr);
    }
};

class Solution {
public:
    // Memoization
    int solve(int n, std::vector<int>& memo) {
        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        int one_step = solve(n - 1, memo);
        int two_step = solve(n - 2, memo);

        memo[n] = one_step + two_step;
        return memo[n];
    }

    int climbStairs(int n) {
        std::vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};

class Solution {
public:
// using buttom up approach
    int solve(int n, vector<int>& arr){
        if(n < 0){
            return 0;
        }

        if(n <= 2){
            return n;
        }

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i = 3; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }

    int climbStairs(int n) {
        vector<int> arr(n+1, -1);
    
        return solve(n, arr);
    }
};

int main() {
    Solution solution;
    int n = 5; // Example input
    std::cout << "Number of ways to climb " << n << " stairs: " << solution.climbStairs(n) << std::endl;
    return 0;
}