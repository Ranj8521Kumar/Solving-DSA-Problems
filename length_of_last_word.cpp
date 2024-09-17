#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;

        while (i >= 0) {
            if (isalnum(s[i])) {
                break;
            }
            i--;
        }

        int n1 = i;

        while (i >= 0) {
            if (s[i] == ' ') {
                break;
            }
            i--;
        }
        return n1 - i;
    }
};

int main() {
    Solution solution;

    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";

    cout << "Last word length in \"" << s1 << "\": " << solution.lengthOfLastWord(s1) << endl;
    cout << "Last word length in \"" << s2 << "\": " << solution.lengthOfLastWord(s2) << endl;
    cout << "Last word length in \"" << s3 << "\": " << solution.lengthOfLastWord(s3) << endl;

    return 0;
}
