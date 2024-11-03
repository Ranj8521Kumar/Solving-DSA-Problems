#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();

        if (n1 != n2) {
            return false;
        }

        for (int i = 0; i < n1; i++) {
            string currString = "";
            int j = i;
            while (j < n1) {
                currString += s[j];
                j++;
            }
            for (int k = 0; k < i; k++) {
                currString += s[k];
            }

            if (currString == goal) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";

    bool result = solution.rotateString(s, goal);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
