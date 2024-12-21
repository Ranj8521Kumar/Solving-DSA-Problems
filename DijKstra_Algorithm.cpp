#include<bits/stdc++.h>
using namespace std;

//using priority queue
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int v = adj.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq; //{node, distance from src}
        
        vector<int> result(v, INT_MAX);
        
        result[src] = 0;
        
        pq.push({src, result[src]});
        
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            
            for(auto &v: adj[u.first]){
                int node = v.first;
                int dist = v.second;
                
                int updatedDist = u.second + dist;
                if(updatedDist < result[node]){
                    result[node] = updatedDist;
                    pq.push({node, updatedDist});
                }
            }
        }
        
        return result;
    }
};

//using set
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src using Dijkstra's Algorithm.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int v = adj.size(); // Total number of vertices in the graph
        
        set<pair<int, int>> st; // Stores pairs {distance from src, node}.
        // A set ensures that the elements are sorted by distance, allowing easy extraction of the node with the smallest distance.

        vector<int> result(v, INT_MAX); // Initialize distances to all vertices as infinity.
        
        result[src] = 0; // Distance from source to itself is 0.
        
        st.insert({result[src], src}); // Insert the source vertex into the set.
        
        while (!st.empty()) {
            auto u = *st.begin(); // Get the node with the smallest distance.
            st.erase(st.begin()); // Remove this node from the set.
            
            // Traverse all neighbors of the current node.
            for (auto &v : adj[u.second]) {
                int node = v.first;   // Neighboring node.
                int dist = v.second;  // Weight of the edge to the neighboring node.
                
                int updatedDist = u.first + dist; // Calculate the updated distance to the neighbor.
                if (updatedDist < result[node]) { // If a shorter distance is found:
                    auto it = st.find({result[node], node}); // Find the existing distance entry for this node in the set.
                    if (it != st.end()) {
                        st.erase(it); // Remove the outdated distance from the set.
                    }
                    
                    result[node] = updatedDist; // Update the shortest distance to this node.
                    st.insert({updatedDist, node}); // Insert the updated distance into the set.
                }
            }
        }
        
        return result; // Return the shortest distances from the source to all vertices.
    }
};


int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<pair<int, int>>> adj(v, vector<pair<int, int>> ());

    for(int i = 0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin>>src;

    Solution obj;
    vector<int> result = obj.dijkstra(adj, src);

    for(int i = 0; i<v; i++){
        cout<<result[i]<<" ";
    }

    return 0;
}