#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        // Total counts
        int n = s.size();
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        for (const auto& it : s) {
            if (it == 'a') {
                count_a++;
            } else if (it == 'b') {
                count_b++;
            } else {
                count_c++;
            }
        }

        if (count_a < k || count_b < k || count_c < k) {
            return -1;
        }

        int i = 0;
        int j = 0;
        int notDeletedWindow = 0;

        while (j < n) {
            char ch = s[j];
            if (ch == 'a') {
                count_a--;
            } else if (ch == 'b') {
                count_b--;
            } else {
                count_c--;
            }

            while (i <= j && (count_a < k || count_b < k || count_c < k)) {
                char ch = s[i];
                if (ch == 'a') {
                    count_a++;
                } else if (ch == 'b') {
                    count_b++;
                } else {
                    count_c++;
                }
                i++;
            }
            notDeletedWindow = max(notDeletedWindow, j - i + 1);
            j++;
        }
        return n - notDeletedWindow;
    }
};

int main() {
    Solution obj;
    cout << obj.takeCharacters("abacba", 2) << endl;
    return 0;
}