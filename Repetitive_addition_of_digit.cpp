#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int singleDigit(int num) {
        // code here
    //     int sum = 0;
    //     while(num > 9){
    //         int n = num;
    //         while(n != 0){
    //             int digit = n%10;
    //             sum += digit;
    //             n /= 10;
    //         }
    //         num = sum;
    //     }
        
    //     return num;
    
    //optimized approach using digital root property
    if(num == 0) return 0;

    //Note: Digital Root Property:
        //The sum of the digits of a number is congruent to the number modulo 9 (except when the number is 0).
    
    return (num % 9 == 0)?9:num%9;//using digital root property
    }
};

int main(){
    Solution obj;
    int num = 12345;
    cout<<obj.singleDigit(num)<<endl;
    return 0;
}