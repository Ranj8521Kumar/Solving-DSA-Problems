#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (const auto &ch : expression) {
            if (ch != ')' && ch != ',') {
                st.push(ch);
            } else if (ch == ')') {
                vector<bool> exp;

                while (!st.empty() && st.top() != '(') {
                    char t = st.top();
                    st.pop();

                    if (t == 't') {
                        exp.push_back(true);
                    } else {
                        exp.push_back(false);
                    }
                }

                st.pop();

                if (!st.empty()) {
                    char t = st.top();
                    st.pop();

                    bool v = exp[0];

                    if (t == '&') {
                        for (auto b : exp) {
                            v = v & b;
                        }
                    } else if (t == '|') {
                        for (auto b : exp) {
                            v = v | b;
                        }
                    } else {
                        v = !exp[0];
                    }

                    if (v) {
                        st.push('t');
                    } else {
                        st.push('f');
                    }
                }
            }
        }
        return st.top() == 't';
    }
};

int main() {
    Solution solution;
    string expression;
    
    cout << "Enter a boolean expression: ";
    cin >> expression;

    bool result = solution.parseBoolExpr(expression);
    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}
