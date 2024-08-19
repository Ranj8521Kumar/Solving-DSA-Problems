//Approach 1

// #include <iostream>

// using namespace std;

// class Solution {
// public:
//     int minFlips(int a, int b, int c) {
//         // Compute (a | b) ^ c
//         int result = (a | b) ^ c;

//         // Compute (a & b) & result
//         int result1 = (a & b);
//         int result2 = (result & result1);

//         // Count bits set in result and result2
//         int flips = __builtin_popcount(result) + __builtin_popcount(result2);// count number of 1 bit in result and result2

//         return flips;
//     }
// };

// int main() {
//     Solution sol;
//     int a = 2, b = 6, c = 5;
//     cout << "Minimum flips required: " << sol.minFlips(a, b, c) << endl;  // Output should be the minimum number of flips required

//     return 0;
// }


//Approach 2

#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        while (a != 0 || b != 0 || c != 0) {
            // Check the current least significant bit of a, b, and c
            if ((c & 1) == 1) {
                // If c's bit is 1, but both a and b's bits are 0, we need a flip
                if ((a & 1) == 0 && (b & 1) == 0) {
                    flips++;
                }
            } else {
                // If c's bit is 0, but either a or b's bits are 1, we need flips
                if ((a & 1) == 1) {
                    flips++;
                }
                if ((b & 1) == 1) {
                    flips++;
                }
            }

            // Right shift to process the next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return flips;
    }
};

int main() {
    Solution sol;
    int a = 2, b = 6, c = 5;
    cout << "Minimum flips required: " << sol.minFlips(a, b, c) << endl;  // Output should be the minimum number of flips required

    return 0;
}

