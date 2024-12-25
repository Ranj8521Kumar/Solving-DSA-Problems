#include <bits/stdc++.h>
using namespace std;

//using DFS to find the diameter of the tree
class Solution {
public:
    pair<int, int> DFS(unordered_map<int, vector<int>>& adj, int u, unordered_map<int, bool>& visited) {
        int maxDist = 0;
        int farthestNode = u;

        visited[u] = true;
        for (auto &v : adj[u]) {
            if (!visited[v]) {
                auto temp = DFS(adj, v, visited);

                if (temp.first + 1 > maxDist) {
                    maxDist = temp.first + 1;
                    farthestNode = temp.second;
                }
            }
        }

        return {maxDist, farthestNode};
    }

    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        auto [maxDist, farthestNode] = DFS(adj, 0, visited); // find one end of the diameter

        visited.clear();
        auto [diameter, secondEnd] = DFS(adj, farthestNode, visited); // find length of the diameter or second length of the diameter

        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);

        int half1 = (d1 + 1) / 2;
        int half2 = (d2 + 1) / 2;

        return max({d1, d2, half1 + half2 + 1});
    }
};

//using BFS to find the diameter of the tree
// class Solution {
// public:
//     pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int u){
//         unordered_map<int, bool> visited;
//         int maxDist = 0;
//         int farthestNode = u;
//         queue<int> que;

//         que.push(u);
//         visited[u] = true;

//         while(!que.empty()){
//             int len = que.size(); //size of current level

//             while(len--){
//                 int u = que.front();
//                 que.pop();
//                 farthestNode = u;

//                 //adding node of next level
//                 for(auto &v: adj[u]){
//                     if(!visited[v]){
//                         visited[v] = true;
//                         que.push(v);
//                     }
//                 }
//             }

//             if(!que.empty()){// if que empty then there is no any level
//                 maxDist++;
//             }
//         }

//         return {maxDist, farthestNode};
//     }


//     int treeDiameter(vector<vector<int>>& edges){
//         unordered_map<int, vector<int>> adj;

//         for(auto &edge: edges){
//             int u = edge[0];
//             int v = edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         auto [maxDist, farthestNode] = BFS(adj, 0);//find one end of the diameter
//         auto [diameter, _] = BFS(adj, farthestNode);//find length of the diameter or second length of  the diameter

//         return diameter;
//     }

//     int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         int d1 = treeDiameter(edges1);
//         int d2 = treeDiameter(edges2);

//         int half1 = (d1+1)/2;
//         int half2 = (d2+1)/2;

//         return max({d1, d2, half1 + half2 + 1});
//     }
// };

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}};
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};

    int result = sol.minimumDiameterAfterMerge(edges1, edges2);
    cout << "Minimum diameter after merging two trees: " << result << endl;

    return 0;
}