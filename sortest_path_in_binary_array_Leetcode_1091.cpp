#include<bits/stdc++.h>
using namespace std;

//using BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {1,1}, {-1, 1}, {-1,0}, {-1, -1}, {0, -1},  {1, -1}};

        if(m <= 0 || n <= 0 || grid[0][0] == 1){
            return -1;
        }

        auto isSafe = [&](int i, int j){
            if(i<0 || j<0 || i>=m || j>=n){
                return false;
            }

            return true;
        };

        int lebel = 0;
        queue<pair<int, int>> que;
        que.push({0, 0});
        grid[0][0] = 1;

        while(!que.empty()){
            int len = que.size();

            while(len--){
                auto u = que.front();
                que.pop();
                int i = u.first;
                int j = u.second;
                
                if(i == m-1 && j == n-1){
                    return lebel + 1;
                }

                for(auto &dir: directions){
                    int i = u.first + dir[0];
                    int j = u.second + dir[1];

                    if(isSafe(i, j) && grid[i][j] != 1){
                        grid[i][j] = 1;
                        que.push({i, j});
                    }
                }
            }

            lebel++;
        }

        return -1;
    }
};

// using Dijkstra's algorithm
class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m <= 0 || n <= 0 || grid[0][0] == 1){
            return -1;
        }

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0,  -1}, {1, -1}};

        // Lambda function for isSafe
        auto isSafe = [&](int i,  int j){
            if(i < 0 || j < 0 || i >= m || j>= n){
                return false;
            }

            return true;
        };

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        int dist = 1;

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            int i = u.second.first;
            int j = u.second.second;
            int d = u.first;

            for(auto &dir: direction){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(isSafe(new_i, new_j) && grid[new_i][new_j] == 0 && (d + dist) < result[new_i][new_j]){
                    pq.push({(d + dist), {new_i, new_j}});
                    result[new_i][new_j] = d + dist;
                }
            }
        }

        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }

        return result[m-1][n-1] + 1;
    }
};

// using simple queue
// since distance between each cell is 1, means equal,so we use directly use queue instead of proirity queue or min-heap
class Solution {
public:
    typedef pair<int, int> p;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m <= 0 || n <= 0 || grid[0][0] == 1){
            return -1;
        }

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0,  -1}, {1, -1}};

        // Lambda function for isSafe
        auto isSafe = [&](int i,  int j){
            if(i < 0 || j < 0 || i >= m || j>= n){
                return false;
            }

            return true;
        };

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));

        queue<p> pq;
        pq.push({0, 0});
        result[0][0] = 0;

        int dist = 1;

        while(!pq.empty()){
            auto u = pq.front();
            pq.pop();

            int i = u.first;
            int j = u.second;

            for(auto &dir: direction){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(isSafe(new_i, new_j) && grid[new_i][new_j] == 0 && (result[i][j] + dist) < result[new_i][new_j]){
                    pq.push({new_i, new_j});
                    result[new_i][new_j] = result[i][j] + dist;
                }
            }
        }

        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }

        return result[m-1][n-1] + 1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

    cout << sol.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}