#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();

        vector<vector<pair<int, int>>> adj(v);
        for(int i = 0; i < v; i++){
            for(int j = i + 1; j < v; j++){
                auto point1 = points[i];
                auto point2 = points[j];

                int wt = abs(point2[0] - point1[0]) + abs(point2[1] - point1[1]);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(v, false);
        pq.push({0, 0});

        int result = 0;

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            int node = u.second;
            int wt = u.first;

            if(visited[node]) continue;

            result += wt;
            visited[node] = true;

            for(auto &v: adj[node]){
                int neighbour = v.first;
                int neighbour_wt = v.second;

                if(!visited[neighbour]){
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    int result = sol.minCostConnectPoints(points);
    cout << "Minimum cost to connect all points: " << result << endl;
    return 0;
}