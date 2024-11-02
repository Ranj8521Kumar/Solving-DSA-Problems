#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        char first = sentence[0];
        char last = sentence[n - 1];

        if (first != last) {
            return false;
        }

        stringstream ss(sentence);
        string word;
        int cnt = 0;
        char fst;
        char lst;

        while (ss >> word) {
            int n = word.size();
            cnt++;
            if (cnt > 1) {
                fst = word[0];
                if (fst != lst) {
                    return false;
                }
            } else {
                fst = word[0];
            }
            lst = word[n - 1];
        }
        return true;
    }
};

int main() {
    Solution solution;
    string testSentence;

    cout << "Enter a sentence: ";
    getline(cin, testSentence);

    if (solution.isCircularSentence(testSentence)) {
        cout << "The sentence is a circular sentence." << endl;
    } else {
        cout << "The sentence is not a circular sentence." << endl;
    }

    return 0;
}
