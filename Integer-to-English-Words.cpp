#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     string numberToWords(int num) {
//         if (num == 0) return "Zero";
//         return helper(num).substr(1);  // Remove leading space
//     }

// private:
//     vector<string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
//     vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
//     vector<string> thousands = {"", "Thousand", "Million", "Billion"};

//     string helper(long num) {
//         if (num == 0) return "";
//         if (num < 20) return " " + lessThan20[num];
//         if (num < 100) return " " + tens[num / 10] + helper(num % 10);
//         if (num < 1000) return " " + lessThan20[num / 100] + " Hundred" + helper(num % 100);

//         for (int i = 1; i < thousands.size(); ++i) {
//             long divisor = 1;
//             for (int j = 0; j < i; ++j) {
//                 divisor *= 1000;
//             }
//             if (num < divisor * 1000) {
//                 return helper(num / divisor) + " " + thousands[i] + helper(num % divisor);
//             }
//         }

//         return "";
//     }
// };


// int main()
// {
//     Solution solution;
//     int num = 1234567891;
//     string result = solution.numberToWords(num);
//     cout << "The number " << num << " in words is: " << result << endl;

//     return 0;
// }
