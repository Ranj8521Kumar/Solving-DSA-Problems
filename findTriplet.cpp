#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1, n = word.size();
        char ch = word[0];
        
        for(int i = 1; i < n; i++) {
            if(word[i] == ch && cnt < 9) {
                cnt++;
            } else {
                comp.push_back(cnt + '0');
                comp.push_back(ch);
                ch = word[i];
                cnt = 1;
            }
        }
        comp.push_back(cnt + '0');
        comp.push_back(ch);
        
        return comp;
    }
};

int main() {
    Solution solution;
    string word1 = "abcde";
    string word2 = "aaaaaaaaaaaaaabb";
    
    cout << "Compressed version of '" << word1 << "': " << solution.compressedString(word1) << endl;
    cout << "Compressed version of '" << word2 << "': " << solution.compressedString(word2) << endl;

    return 0;
}
