#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (auto &ch : s) {
            if (!isdigit(ch)) {
                st.push(ch);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            char ch = st.top(); // Changed int to char
            st.pop();
            result += ch;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution solution;
    string input = "a1b2c3d4";
    string output = solution.clearDigits(input);
    cout << "Output: " << output << endl;
    return 0;
}