#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        while (true) {
            int pos = s.find(part);

            if (pos == string::npos) {
                break;
            } else {
                s.erase(pos, m);
            }
        }

        return s;
    }
};

int main() {
    Solution solution;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = solution.removeOccurrences(s, part);
    cout << "Result: " << result << endl;
    return 0;
}