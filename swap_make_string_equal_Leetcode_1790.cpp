#include <bits/stdc++.h>
using namespace std;

//First Approach
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n != m){
            return false;
        }

        vector<int> diffIndices;

        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]){
                diffIndices.push_back(i);
            }
        }

        if(diffIndices.size() > 2){
            return false;
        }else if(diffIndices.size() == 0){
            return true;
        }else if(diffIndices.size() == 1){
            return false;
        }

        int i = diffIndices[0];
        int j = diffIndices[1];

        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};

//Second Approach
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n != m){
            return false;
        }

        unordered_map<char, int> mpp;

        for(auto &ch: s1){
            mpp[ch]++;
        }

        for(auto &ch: s2){
            mpp[ch]--;
        }

        for(auto &it: mpp){
            if(it.second != 0){
                return false;
            }
        }

        int numberSwap = 0;
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]){
                numberSwap++;
            }

            if(numberSwap > 2){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "bank";
    string s2 = "kanb";
    cout << "Are Almost Equal: " << sol.areAlmostEqual(s1, s2) << endl;
    return 0;
}