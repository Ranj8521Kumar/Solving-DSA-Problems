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

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        //using khan's algorithm or using bfs or using topological sort
        
        int v = adj.size();
        
        vector<int> indegree(v, 0);
        
        for(int u = 0; u<v; u++){
            for(auto &v: adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
            }
        }
        
        int count = 0;
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            count++;
            
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }
        
        if(count !=  v){ //if topological sort is not possible means no of element in topological sort in not equa to total number of vertices, then cycle is present
            return true;
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