#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, unordered_set<int>> row_map, col_map;
        unordered_map<int, int> parent;

        for (int i = 0; i < stones.size(); ++i) {
            int x = stones[i][0];
            int y = stones[i][1];
            row_map[x].insert(i);
            col_map[y].insert(i);
            parent[i] = i;
        }

        function<int(int)> find = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);
            }
            return parent[node];
        };

        function<void(int, int)> union_sets = [&](int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 != root2) {
                parent[root2] = root1;
            }
        };

        for (auto& [row, indices] : row_map) {
            auto it = indices.begin();
            int first = *it++;
            while (it != indices.end()) {
                union_sets(first, *it++);
            }
        }

        for (auto& [col, indices] : col_map) {
            auto it = indices.begin();
            int first = *it++;
            while (it != indices.end()) {
                union_sets(first, *it++);
            }
        }

        unordered_set<int> unique_roots;
        for (int i = 0; i < stones.size(); ++i) {
            unique_roots.insert(find(i));
        }

        return stones.size() - unique_roots.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    
    cout << "Maximum stones that can be removed: " << sol.removeStones(stones1) << endl;
    return 0;
}
