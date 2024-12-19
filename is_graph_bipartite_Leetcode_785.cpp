#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<int>& color, int currColor){
        color[u] = currColor;

        for(auto &v: adj[u]){
            if(color[v] == color[u]){// Same color on both ends of an edge
                return false;
            }else{
                if(color[v] == -1){
                    if(color[u] == 1){
                        color[v] = 0;
                    }else{
                        color[v] = 1;
                    }

                    //or, for assigning color
                    //color[v] = 1 - color[u]; // for opposite color

                    if(!DFS(adj, v, color, color[v])){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        //red -> 1
        //blue -> 0
        //no-color -> -1
        vector<int> color(v, -1);

        for(int u = 0; u<v; u++){
            if(color[u] == -1){
                int currColor = 1; // Assign initial color
                if(!DFS(graph, u, color, currColor)){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>> graph(n);

    for(int i = 0; i<n; i++){
        int m;
        cin>>m;

        vector<int> temp(m);

        for(int j = 0; j<m; j++){
            cin>>temp[j];
        }

        graph[i] = temp;
    }

    Solution obj;

    cout<<obj.isBipartite(graph)<<endl;

    return 0;
}