#include<bits/stdc++.h>
using namespace std;


//using DFS
class Solution {
  public:
    //function for isCycleDFS
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<int>&visited, int parent){
        visited[u] = true;
        
        for(auto &v: adj[u]){
            // if(visited[v] && v != parent){
            //     return true;
            // }
            
            // if(!visited[v]){
            //     if(isCycleDFS(adj, v, visited, u)){
            //         return true;
            //     }
            // }
            
            if(v == parent){
                continue;
            }
            
            if(visited[v]){
                return true;
            }
            
            if(isCycleDFS(adj, v, visited, u)){
                return true;
            }
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        
        vector<int> visited(v, false);
        
        for(int u = 0; u<v; u++){ // for not connected graph
            if(!visited[u] && isCycleDFS(adj, u, visited, -1)){
                return true;
            }
        }
        
        return false;
    }
};

//using BFS
class Solution {
  public:
    //function for isCycleBFS
    bool isCycleBFS(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent){
        queue<pair<int, int>> que;
        
        que.push({u, parent});
        visited[u] = true;
        
        
        while(!que.empty()){
            auto u = que.front();
            que.pop();
            
            for(auto &v: adj[u.first]){
                // if(v == u.second) continue;
                
                // if(visited[v]){
                //     return true;
                // }
                
                // que.push({v, u.first});
                // visited[v] = true;
                
                if(visited[v]  && v != u.second){
                    return true;
                }
                
                if(!visited[v]){
                    que.push({v, u.first});
                    visited[v] = true;
                }
            }
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        
        vector<bool> visited(v, false);
        
        for(int u  = 0; u<v; u++){
            if(!visited[u] && isCycleBFS(adj, u, visited, -1)){
                return true;
            }
        }
        
        return false;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    cout<<obj.isCycle(adj)<<endl;
    return 0;
}