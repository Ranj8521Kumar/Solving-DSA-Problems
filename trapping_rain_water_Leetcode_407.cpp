#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

         if (m <= 2 || n <= 2) return 0; // No space to trap water

        int trapedWater = 0;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<p, vector<p>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        // push first column and last column in the min-heap
        for(int i = 0; i<m; i++){
            for(auto col: {0, n-1}){
                pq.push({heightMap[i][col], {i, col}});
                visited[i][col] = true;
            }
        }

        // push first row and last row in the min-heap
        for(int j = 0; j<n; j++){
            for(auto row: {0, m-1}){
                pq.push({heightMap[row][j], {row, j}});
                visited[row][j] = true;
            }
        }

        while(!pq.empty()){
            auto pp = pq.top();
            pq.pop(); // O(log(size of the heap))

            int height = pp.first;
            int  i = pp.second.first;
            int  j = pp.second.second;

            for(auto &dir: directions){
                int neg_i = i + dir[0];
                int neg_j = j + dir[1];

                if(neg_i<m && neg_i>=0 && neg_j<n && neg_j>=0 && !visited[neg_i][neg_j]){
                    trapedWater += max(height-heightMap[neg_i][neg_j], 0);
                    pq.push({max(height, heightMap[neg_i][neg_j]), {neg_i, neg_j}});
                    visited[neg_i][neg_j] = true;
                }
            }
        }

        return trapedWater;
    }
};

int main(){
    Solution s;
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},
                                     {3,2,1,3,2,4},
                                     {2,3,3,2,3,1}};

    cout<<s.trapRainWater(heightMap)<<endl;
    return 0;
}