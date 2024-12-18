#include<bits/stdc++.h>
using namespace std;

//using dfs and stack
class Solution {
  public:
    //function for dfs call
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited, st);
            }
        }
        
        st.push(u);
    }
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int v = adj.size();
        
        vector<bool> visited(v, false);
        stack<int> st;
        
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                DFS(adj, u, visited, st);
            }
        }
        
        vector<int> result;
        
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            
            result.push_back(it);
        }
        
        return result;
    }
};


//using BFS and queue or khan's algorithm
class Solution {
  public:
    // Function for BFS call
    void BFS(vector<vector<int>>& adj, vector<int>& indegree, queue<int>& que, vector<int>& result){
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            result.push_back(u);

            for (auto &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> indegree(v, 0);

        // Calculate indegree of all vertices
        for (int u = 0; u < v; u++) {
            for (auto &node : adj[u]) {
                indegree[node]++;
            }
        }

        vector<int> result;

        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u); // push all vetices of indegree Zero
            }
        }
        
        
        
        BFS(adj, indegree, que, result);
        
        return result;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> adj = {{1, 2}, {2}, {0}};
    vector<int> result = obj.topologicalSort(adj);
    for(auto &it: result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}