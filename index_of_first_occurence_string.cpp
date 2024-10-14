#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();

        if (n2 == 0) {
            return 0;
        }

        if (n1 < n2) {
            return -1;
        }

        int i = 0, j = 0;
        while (i < n1) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
                if (j == n2) {
                    return i - j;
                }
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    int index = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl;

    return 0;
}
