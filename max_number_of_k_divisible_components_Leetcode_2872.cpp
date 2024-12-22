#include <iostream>
#include <vector>

using namespace std;

//first approach
class Solution {
public:
    long DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& values, int k, int& count){
        visited[u] =  true;
        long sum = 0;

        for(auto &v: adj[u]){
            if(!visited[v]){
                sum += DFS(adj, v, visited, values, k, count);
                visited[v] = true;
            }
        }

        sum += values[u];

        if(sum % k == 0){
            count++;
            sum = 0;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int u = 0; u<n; u++){
            if(!visited[u]){
                DFS(adj, u, visited, values, k, count);
            }
        }

        return count;
    }
};

//second approach
class Solution {
public:
    long DFS(vector<vector<int>>& adj, int u, int parentNode, int k, vector<int>& values, int &componentsCount) {
        long sum = 0;
        for(auto &v: adj[u]) {
            if(v != parentNode) {
                sum += DFS(adj, v, u, k, values, componentsCount);
            }
        }

        sum += values[u];
        if(sum % k == 0) {
            componentsCount++;
            sum = 0;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int v = n;
        vector<vector<int>> adj(v);
        
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int componentsCount = 0;
        DFS(adj, 0, -1, k, values, componentsCount);

        return componentsCount;
    }
};

int main() {
    Solution solution;
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 3;

    int result = solution.maxKDivisibleComponents(n, edges, values, k);
    cout << "Maximum number of k-divisible components: " << result << endl;

    return 0;
}