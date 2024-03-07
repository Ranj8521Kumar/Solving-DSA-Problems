#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            int start = i;
            int end = min(i + k - 1, n - 1);
            while (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};

int main()
{
    Solution obj;
    string s="Ranjan";
    cout<<obj.reverseStr(s,2);
    return 0;
}