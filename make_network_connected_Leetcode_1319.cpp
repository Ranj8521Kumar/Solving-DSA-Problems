#include<bits/stdc++.h>
using namespace std;

// using DSU(disjoint set union-find)
class Solution {
public:
    int find(int u, vector<int>& parent){
        if(u  == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, int &components){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if(parent_u != parent_v){
            parent[parent_v] = parent[u];
            components--;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int v = n;

        int edges = connections.size();

        if(edges < v-1) return -1;

        vector<int> parent(v);

        for(int u = 0; u<v; u++){
            parent[u] = u;
        }

        int components = v;

        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            unionSet(u, v, parent, components);
        }

        return components - 1;
    }
};

// using BFS
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        int v = n;
        int edges = connections.size();

        if(edges < v-1) return -1;

        vector<vector<int>> adj(v, vector<int> ());

        int components = 0;

        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(v, false);

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                components++;
                BFS(adj, u, visited);
            }
        }

        return components - 1;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

    Solution obj;
    cout<<obj.makeConnected(n, connections)<<endl;

    return 0;
}