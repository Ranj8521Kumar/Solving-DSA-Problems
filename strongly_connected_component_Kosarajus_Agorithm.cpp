#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        void DFSForTopoSort(vector<vector<int>>& adj, int u, vector<int>& visited, stack<int>& st) {
                visited[u] = true;
                
                for(auto &v: adj[u]) {
                        if(!visited[v]) {
                                DFSForTopoSort(adj, v, visited, st);
                        }
                }
                
                st.push(u);
        }
    
        void topologicalSort(vector<vector<int>>& adj, stack<int>& st) {
                int v = adj.size();
                vector<int> visited(v, false);
                
                for(int u = 0; u < v; u++) {
                        if(!visited[u]) {
                                DFSForTopoSort(adj, u, visited, st);
                        }
                }
        }
    
        void DFS(vector<vector<int>>& adj, int u, vector<int>& visited) {
                visited[u] = true;
                
                for(auto &v: adj[u]) {
                        if(!visited[v]) {
                                DFS(adj, v, visited);
                        }
                }
        }
    
        int kosaraju(vector<vector<int>> &adj) {
                int v = adj.size();
                
                // For topological sort
                stack<int> st;
                topologicalSort(adj, st);
                
                // Reverse the edges of the original graph to create a reversedGraph
                vector<vector<int>> reversedGraph(v);
                for(int i = 0; i < v; i++) {
                        for(auto &node: adj[i]) {
                                reversedGraph[node].push_back(i);
                        }
                }
                
                // Visited array for DFS calls
                vector<int> visited(v, false);
                
                int count = 0;
                
                // Call DFS in the order of topological sort stored in the stack
                while(!st.empty()) {
                        int u = st.top();
                        st.pop();
                        
                        if(!visited[u]) {
                                DFS(reversedGraph, u, visited);
                                count++;
                        }
                }
                
                return count;
        }
};

int main() {
        Solution sol;
        vector<vector<int>> adj = {
                {1},
                {2},
                {0, 3},
                {4},
                {}
        };
        
        int result = sol.kosaraju(adj);
        cout << "Number of Strongly Connected Components: " << result << endl;
        
        return 0;
}