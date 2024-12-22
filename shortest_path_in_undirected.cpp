#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adjMatrix, int src)
    {
        // code here

        // using BFS
        int v = adjMatrix.size();
        vector<vector<int>> adj(v);

        for (int i = 0; i < v; i++)
        {
            vector<int> vec = adjMatrix[i];
            int len = vec.size();

            for (int j = 0; j < len; j++)
            {
                adj[i].push_back(vec[j]);
                adj[vec[j]].push_back(i);
            }
        }

        vector<int> distance(v, INT_MAX);
        distance[src] = 0;

        vector<int> parent(v, -1);
        vector<bool> visited(v, false);

        int u = src;
        if (!visited[u])
        {
            queue<int> que;
            que.push(u);
            visited[u] = true;

            while (!que.empty())
            {
                auto u = que.front();
                que.pop();

                for (auto &v : adj[u])
                {
                    if (!visited[v])
                    {
                        que.push(v);
                        visited[v] = true;
                        distance[v] = distance[u] + 1;
                        parent[v] = u;
                    }
                }
            }
        }

        for (int u = 0; u < v; u++)
        {
            if (distance[u] == INT_MAX)
            {
                distance[u] = -1;
            }
        }

        return distance;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    vector<int> res = obj.shortestPath(edges, 0);
    for (auto &i : res)
    {
        cout << i << " ";
    }
    return 0;
}