#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mpp;
    vector<string> result;

    void stringStream(string str) {
        stringstream ss(str);
        string word;
        while (ss >> word) {
            mpp[word]++;
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        stringStream(s1);
        stringStream(s2);

        for (auto it : mpp) {
            if (it.second == 1) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "this is a test";
    string s2 = "this is not a drill";
    vector<string> res = sol.uncommonFromSentences(s1, s2);

    for (string word : res) {
        cout << word << " ";
    }
    return 0;
}
