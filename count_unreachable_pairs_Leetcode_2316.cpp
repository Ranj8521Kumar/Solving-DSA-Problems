#include<bits/stdc++.h>
using namespace std;

// using BFS
class Solution {
public:
    void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& nodeCount){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        int count = 0;

        while(!que.empty()){
            int u = que.front();
            count++;
            que.pop();

            for(auto &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }

        nodeCount.push_back(count);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int v = n;
        vector<vector<int>> adj(v, vector<int> ());

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(v, false);
        vector<int> nodeCount;

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                BFS(adj, u, visited, nodeCount);
            }
        }

        long long result = 0;
        long long nodeSum = 0;

        for(auto &count: nodeCount){
            result += count*nodeSum;
            nodeSum += count;
        }

        return result;
    }
};

//using dsu(disjoint set union-find)
class Solution {
public:
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if(parent_u != parent_v){
            if(rank[parent_u] == rank[parent_v]){
                parent[parent_u] = parent_v;
                rank[parent_u]++;
            }else if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
            }else{
                parent[parent_u] = parent_v;
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {   
        //using DSU
        int v = n;

        vector<int> parent(v);
        vector<int> rank(v, 0);

        for(int u = 0; u<v; u++){
            parent[u] = u;
        }
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            unionSet(u, v, parent, rank);
        }

        //count number of nodes in a component
        unordered_map<int, int> count;
        for(int u  = 0; u<v; u++){
            count[find(u, parent)]++;
        }

        long long remainingNode = v;
        long long result = 0;

        for(auto &it: count){
            remainingNode -= it.second;
            result += it.second*remainingNode;
        }

        return result;
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>> edges;
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }

    Solution obj;
    cout<<obj.countPairs(n, edges)<<endl;

    return 0;
}