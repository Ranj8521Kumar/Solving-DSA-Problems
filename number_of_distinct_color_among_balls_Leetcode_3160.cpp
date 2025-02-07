#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> distinctColors;
        unordered_map<int, int> colored;
        vector<int> result;

        for(auto &query: queries){
            int ball = query[0];
            int newColor = query[1];

            if(colored.find(ball) != colored.end()){
                int oldColor = colored[ball];

                if(--distinctColors[oldColor] == 0){
                    distinctColors.erase(oldColor);
                }
            }

            colored[ball] = newColor;
            distinctColors[newColor]++;
            result.push_back(distinctColors.size());
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> queries = {{1, 1}, {2, 2}, {1, 2}, {3, 3}};
    int limit = 3; // This parameter is not used in the current implementation

    vector<int> results = sol.queryResults(limit, queries);

    for(int res : results) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}