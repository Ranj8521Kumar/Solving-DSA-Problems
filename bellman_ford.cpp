#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> distance(v, 100000000);
        distance[src] = 0;
        
        for(int relax = 1; relax<=v-1; relax++){
            for(auto &edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(distance[u] != 100000000 && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                }
            }
        }
        
            for(auto &edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(distance[u] != 100000000 && distance[u] + wt < distance[v]){
                    return {-1};//Detect negative cycle
                }
            }
        
        return distance;
    }
};

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges(m, vector<int> (3));

    for(int i = 0; i<m; i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }

    int src;
    cin>>src;

    Solution s;
    vector<int> result = s.bellmanFord(n, edges, src);

    for(auto &i: result){
        cout<<i<<" ";
    }

    return 0;
}