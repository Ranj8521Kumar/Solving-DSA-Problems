#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    public:
        typedef pair<int, pair<int, int>> p;
        // Function to find sum of weights of edges of the Minimum Spanning Tree.
        int spanningTree(int v, vector<vector<int>> adj[]) {
                vector<bool> visited(v, false);
                vector<int> parent(v, -1);
                
                priority_queue<p, vector<p>, greater<p>> pq;
                pq.push({0, {0, -1}}); //{wt, {node, from}}
                
                int result = 0;
                
                while(!pq.empty()){
                        auto u = pq.top();
                        pq.pop();
                        
                        int includedNodeWithMST = u.second.first;
                        int from = u.second.second;
                        int wt = u.first;
                        
                        if(visited[includedNodeWithMST]) continue; //already included in MST
                        
                        visited[includedNodeWithMST] = true;
                        parent[includedNodeWithMST] = from;
                        result += wt;
                        
                        for(auto &v: adj[includedNodeWithMST]){
                                int node = v[0];
                                int wt = v[1];
                                
                                if(!visited[node]){
                                        pq.push({wt, {node, includedNodeWithMST}});
                                }
                        }
                }
                
                return result;
        }
};

//without parent array
class Solution {
  public:
    typedef pair<int, int> p;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]) {
        // code here
        vector<bool> visited(v, false);
        
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0}); //{wt, node}
        
        int result = 0;
        
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            
            int includedNodeWithMST = u.second;
            int wt = u.first;
            
            if(visited[includedNodeWithMST]) continue; //already include in MSt
            
            visited[includedNodeWithMST] = true;
            result += wt;
            
            for(auto &v: adj[includedNodeWithMST]){
                int node = v[0];
                int wt = v[1];
                
                if(!visited[node]){
                    pq.push({wt, node});
                }
            }
        }
        
        return result;
    }
};

int main() {
        int V = 5;
        vector<vector<int>> adj[V];

        adj[0].push_back({1, 2});
        adj[0].push_back({3, 6});
        adj[1].push_back({0, 2});
        adj[1].push_back({2, 3});
        adj[1].push_back({3, 8});
        adj[1].push_back({4, 5});
        adj[2].push_back({1, 3});
        adj[2].push_back({4, 7});
        adj[3].push_back({0, 6});
        adj[3].push_back({1, 8});
        adj[4].push_back({1, 5});
        adj[4].push_back({2, 7});

        Solution obj;
        int result = obj.spanningTree(V, adj);
        cout << "Sum of weights of edges of the Minimum Spanning Tree: " << result << endl;

        return 0;
}