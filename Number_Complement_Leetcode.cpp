#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int bitLength = 0;
        int temp = num;
        while (temp > 0) {
            bitLength++;
            temp >>= 1;
        }
        
        unsigned int mask = (1U << bitLength) - 1;
        return mask - num;  //  mask ^ num 
    }
};

int main() {
    Solution sol;

    int num1 = 5;
    cout << "Complement of " << num1 << " is " << sol.findComplement(num1) << endl;
    
    return 0;
}
