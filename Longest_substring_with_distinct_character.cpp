#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
//     public:
//         int longestUniqueSubstr(string &s) {
//                 unordered_set<char> vis;
                
//                 int n = s.size();
//                 int i = 0;
//                 int j = 0;
                
//                 int count = 0;
                
//                 while (j < n) {
//                         while (vis.find(s[j]) != vis.end()) {
//                                 vis.erase(s[i]);
//                                 i++;
//                         }
                        
//                         vis.insert(s[j]);
//                         count = max(count, j - i + 1);
//                         j++;
//                 }
                
//                 return count;
//         }
// };


//secodn approach
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<bool> vis(26, false);
        
        int n = s.size();
        int i = 0;
        int j = 0;
        
        int count = 0;
        
        while(j < n){
            while(vis[s[j] - 'a'] == true){
               vis[s[i] - 'a'] = false;
               i++;
            }
            
            vis[s[j] - 'a'] = true;
            count = max(count, j - i + 1);
            j++;
        }
        
        return count;
    }
};

int main() {
        Solution sol;
        string s = "abcabcbb";
        cout << "The length of the longest substring with all distinct characters is: " << sol.longestUniqueSubstr(s) << endl;
        return 0;
}