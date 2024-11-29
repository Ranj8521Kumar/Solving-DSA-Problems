#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        string result = "";

        int i = n1 - 1;
        int j = n2 - 1;

        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0;

            int sum = bit1 + bit2 + carry;

            carry = sum / 2;

            result += (sum % 2) + '0';
        }

        reverse(result.begin(), result.end());

        // int k = 0;
        // while (k < result.size() && result[k] == '0') {
        //     k++;
        // }

        // int n = result.size();
        // string finalResult = "";

        // for (int i = k; i < n; i++) {
        //     finalResult += result[i];
        // }

        // return finalResult == "" ? "0" : finalResult;

        //removeLeading Zeros
        size_t pos = result.find_first_not_of('0');
        return pos==string::npos ? "0" :result.substr(pos);    
    }
};

int main() {
    Solution obj;
    string s1 = "11";
    string s2 = "1";
    cout << obj.addBinary(s1, s2);
    return 0;
}