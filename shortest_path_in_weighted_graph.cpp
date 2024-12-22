#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int v = n;
        vector<vector<pair<int, int>>> adj(v+1);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> distance(v+1, INT_MAX);
        distance[1] = 0;

        vector<int> parent(v+1, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            for(auto &v: adj[u.second]){
                int node = v.first;
                int weight = v.second;

                int updatedDistance = u.first + weight;

                if(updatedDistance < distance[node]){
                    distance[node] = updatedDistance;
                    parent[node] =  u.second;
                    pq.push({updatedDistance, node});
                }
            }
        }

        if(distance[v] == INT_MAX){
            return  {-1};
        }

        vector<int> path;
        int current = v;

        while(current != -1){
            path.push_back(current);
            current = parent[current];
        }

        path.push_back(distance[v]);

        reverse(path.begin(), path.end());

        return path;
    }
};

int main(){
    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {{1, 2, 1}, {2, 3, 7}, {2, 4, 5}, {3, 5, 2}, {4, 5, 3}, {1, 5, 4}};

    Solution obj;
    vector<int> ans = obj.shortestPath(n, m, edges);

    for(auto &x: ans){
        cout<<x<<" ";
    }

    return 0;
}