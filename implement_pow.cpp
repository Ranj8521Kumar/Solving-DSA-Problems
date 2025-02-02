#include <iostream>

class Solution {
  public:
    double power(double b, int e) {
        // code here
        
        // //first method
        // return pow(b, e);
        
        //second method
        if(e == 0) return 1;
        
        if(e == 1) return b;
        
        if(e < 0) return 1/power(b, -e);
        
        if(e%2 == 0){
            return power(b*b, e/2);
        }else{
            return power(b, e-1)*b;
        }
    }
};

int main() {
    Solution sol;
    double base = 2.0;
    int exponent = -3;
    std::cout << "Result: " << sol.power(base, exponent) << std::endl;
    return 0;
}