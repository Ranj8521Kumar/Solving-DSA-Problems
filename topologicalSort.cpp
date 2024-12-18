#include<bits/stdc++.h>
using namespace std;

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