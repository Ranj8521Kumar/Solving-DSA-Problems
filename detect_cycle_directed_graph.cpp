#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //function for isCycleDFS
    bool isCycleDFS(vector<vector<int>>& adj, int u,  vector<bool>& visited, vector<bool>& recVisited){
        visited[u] = true;
        recVisited[u] = true;
        
        for(auto &v: adj[u]){
            if(visited[v] && recVisited[v]){
                return true;
            }else{
                if(!visited[v]){
                    if(isCycleDFS(adj, v, visited, recVisited)){
                        return true;
                    }
                }
            }
        }
        recVisited[u] = false;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int v = adj.size();
        
        vector<bool> visited(v, false);
        vector<bool> recVisited(v, false);
        
        for(int u = 0;  u<v; u++){
            if(!visited[u] && isCycleDFS(adj, u, visited, recVisited)){
                return true;
            }
        }
        
        return false;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> adj = {{1, 2}, {2}, {0}};
    cout<<obj.isCyclic(3, adj)<<endl;
    return 0;
}