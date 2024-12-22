#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        if(m <= 0 || n <= 0){
            return -1;
        }

        auto isSafe = [&](int i, int j){
            if(i < 0 || j < 0 || i >= m || j >= n){
                return false;
            }

            return true;
        };

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            int i = u.second.first;
            int j = u.second.second;
            int d = u.first; // current effort

            if (i == m - 1 && j == n - 1) {
                return d;
            }

            for(auto &dir: direction){
                int next_i = i + dir[0];
                int next_j = j + dir[1];

                if(isSafe(next_i, next_j)){
                    int updatedEffort =  max(d, abs(heights[next_i][next_j] - heights[i][j]));
                    if((updatedEffort) < result[next_i][next_j]){
                        pq.push({updatedEffort, {next_i, next_j}});
                        result[next_i][next_j] = updatedEffort;
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};

    cout << sol.minimumEffortPath(heights) << endl;

    return 0;
}