#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Using Kruskal's algorithm

    // Find function
    int find(int u, vector<int>& parent) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u], parent);
    }

    // UnionSet function
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if (rank[parent_u] == rank[parent_v]) {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        } else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        } else {
            parent[parent_u] = parent_v;
        }
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adjMatrix[]) {
        vector<vector<int>> adj;
        for (int node = 0; node < v; node++) {
            for (auto& u : adjMatrix[node]) {
                int v = u[0];
                int wt = u[1];

                if (node < v) {  // Ensure we don't add the same edge twice
                    adj.push_back({node, v, wt});
                }
            }
        }

        vector<int> parent(v);
        for (int u = 0; u < v; u++) {
            parent[u] = u;
        }

        vector<int> rank(v, 0);

        sort(adj.begin(), adj.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int result = 0;

        for (auto& edge : adj) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (find(u, parent) != find(v, parent)) {
                unionSet(u, v, parent, rank);
                result += wt;
            }
        }

        return result;
    }
};

int main() {
    int v = 4; // Number of vertices
    vector<vector<int>> adjMatrix[4] = {
        {{1, 1}, {2, 3}},
        {{0, 1}, {2, 1}, {3, 6}},
        {{0, 3}, {1, 1}, {3, 2}},
        {{1, 6}, {2, 2}}
    };

    Solution sol;
    int result = sol.spanningTree(v, adjMatrix);
    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << result << endl;

    return 0;
}