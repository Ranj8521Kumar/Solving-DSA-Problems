#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.size();
        long long result = 0;
        long long oneCount = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                oneCount++;
            } else {
                result += oneCount;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "1101001";
    cout << sol.minimumSteps(s) << endl;
    return 0;
}
