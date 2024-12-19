#include<bits/stdc++.h>
using namespace std;

//using dfs and stack
class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        vector<vector<int>> adj(v+1, vector<int> ()); //or
        //vector<vector<int>> adj(v+1);

        for(int i =  0; i<v; i++){
            for(int j =  0; j<v; j++){
                int u = isConnected[i][j];
                if(u == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool> visited(v+1, 0);

        int count = 0;
        for(int u = 1; u<=v; u++){
            if(!visited[u]){
                DFS(adj, u, visited);
                count++;
            }
        }

        return count;
    }
};

//second approach
class Solution {
public:
    int v;

    void DFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
        visited[u] = true;

        for(int j = 0; j<v; j++){
            if(!visited[j] && isConnected[u][j] == 1){
                DFS(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        v = isConnected.size();

        vector<bool> visited(v, 0);

        int count = 0;
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                DFS(isConnected, u, visited);
                count++;
            }
        }

        return count;
    }
};

//using bfs and queue
class Solution {
public:
    void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(auto &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        vector<vector<int>> adj(v+1, vector<int> ()); //or
        //vector<vector<int>> adj(v+1);

        for(int i =  0; i<v; i++){
            for(int j =  0; j<v; j++){
                int u = isConnected[i][j];
                if(u == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool> visited(v+1, 0);

        int count = 0;
        for(int u = 1; u<=v; u++){
            if(!visited[u]){
                BFS(adj, u, visited);
                count++;
            }
        }

        return count;
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>> isConnected(n, vector<int> (n));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>isConnected[i][j];
        }
    }

    Solution obj;

    cout<<obj.findCircleNum(isConnected);

    return 0;
}