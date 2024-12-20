#include<bits/stdc++.h>
using namespace std;

//first method
class Solution
{
    public:
    //function for find
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }
        
        return find(parent[u], parent);
    }
    
    void unionSet(int u,  int v, vector<int>& parent){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);
        
        if(parent_u !=  parent_v){
            parent[parent_u] = parent_v;
        }
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int v, vector<int>adj[])
	{
	    // Code here
	    vector<int> parent(v);
	    
	    for(int u = 0; u<v; u++){
	        parent[u] = u;
	    }
	    
	    for(int u = 0; u<v; u++){
	        for(auto &v: adj[u]){
	            if(u<v){
	                int parent_u = find(u, parent);
	                int parent_v = find(v, parent);
	                
	                if(parent_u == parent_v){
	                    return true;
	                }
	                
	                unionSet(u, v, parent);
	            }
	        }
	    }
	    
	    return false;
	}
};

//second method
class Solution
{
    public:
    //function for find
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }
        
        return find(parent[u], parent);
    }
    
    void unionSet(int parent_u,  int parent_v, vector<int>& parent){
        parent[parent_u] = parent_v;
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int v, vector<int>adj[])
	{
	    // Code here
	    vector<int> parent(v);
	    
	    for(int u = 0; u<v; u++){
	        parent[u] = u;
	    }
	    
	    for(int u = 0; u<v; u++){
	        for(auto &v: adj[u]){
	            if(u<v){
	                int parent_u = find(u, parent);
	                int parent_v = find(v, parent);
	                
	                if(parent_u == parent_v){
	                    return true;
	                }
	                
	                unionSet(parent_u, parent_v, parent);
	            }
	        }
	    }
	    
	    return false;
	}
};

//third method
//using rank and path compression
class Solution
{
    public:
    //function for find
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }
        
        return (parent[u] = find(parent[u], parent));
    }
    
    void unionSet(int u,  int v, vector<int>& parent, vector<int>& rank){
        int parent_u = find(u, parent);
        int parent_v =  find(v, parent);
        
        if(parent_u == parent_v){
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }else if(parent_u > parent_v){
            parent[parent_v] = parent_u;
        }else{
            parent[parent_u] = parent_v;
        }
    }
    
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int v, vector<int>adj[])
	{
	    // Code here
	    vector<int> parent(v);
	    vector<int> rank(v, 0);
	    
	    for(int u = 0; u<v; u++){
	        parent[u] = u;
	    }
	    
	    for(int u = 0; u<v; u++){
	        for(auto &v: adj[u]){
	            if(u<v){
	                int parent_u = find(u, parent);
	                int parent_v = find(v, parent);
	                
	                if(parent_u == parent_v){
	                    return true;
	                }
	                
	                unionSet(u, v, parent, rank);
	            }
	        }
	    }
	    
	    return false;
	}
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v, e;
        cin>>v>>e;
        
        vector<int> adj[v];
        
        for(int i = 0; i<e; i++){
            int u, v;
            cin>>u>>v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        Solution obj;
        bool ans = obj.detectCycle(v, adj);
        
        if(ans){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
    return 0;
}