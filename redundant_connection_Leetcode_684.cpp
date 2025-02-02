#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unionSet(int parent_u, int parent_v) {
        if (rank[parent_u] == rank[parent_v]) {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        } else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        } else {
            parent[parent_u] = parent_v;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int u = 1; u <= n; u++) {
            parent[u] = u;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u == parent_v) {
                return edge;
            }

            unionSet(parent_u, parent_v);
        }

        return {};
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result = solution.findRedundantConnection(edges);

    cout << "Redundant connection: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}