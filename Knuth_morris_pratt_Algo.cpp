#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> compute_pie_table(string needle, int m) {
        vector<int> pieTable(m, 0);
        int k = 0;

        for (int i = 1; i < m; i++) {
            while (k > 0 && needle[k] != needle[i]) {
                k = pieTable[k - 1];
            }
            if (needle[k] == needle[i]) {
                k++;
            }
            pieTable[i] = k;
        }
        return pieTable;
    }

public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0; // Handle empty needle edge case

        vector<int> pieTable = compute_pie_table(needle, m);

        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = pieTable[j - 1];
            }
            if (needle[j] == haystack[i]) {
                j++;
                if (j == m) {
                    return i - m + 1; // Return starting index of match
                }
            }
        }
        return -1; // No match found
    }
};

int main() {
    Solution obj;
    string haystack = "hello";
    string needle = "ll";
    cout << obj.strStr(haystack, needle);
    return 0;
}