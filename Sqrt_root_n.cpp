#include <iostream>

using namespace std;

class Solution {
public:
    long long int floorSqrt(long long int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        
        long long low = 1, high = n, ans = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            
            if(mid * mid == n) {
                return mid;
            } else if(mid * mid < n) {
                low = mid + 1;
                ans = mid; // for floor value if ans is floating
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    long long int n;
    cout << "Enter a number: ";
    cin >> n;

    long long int result = sol.floorSqrt(n);
    cout << "The floor value of the square root of " << n << " is " << result << endl;

    return 0;
}