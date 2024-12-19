#include<bits/stdc++.h>
using namespace std;

//using BFS and queue or khan's algorithm
class Solution {
public:
    void BFS(unordered_map<int, vector<int>>& adj, vector<int>& indegree, vector<int>& result, int v){
        queue<int> que;
        int count = 0;

        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
                count++;
            }
        }

        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();

            for(auto &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }

        if(count != v){
            result  = {};
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int n = prerequisites.size();

        vector<int> result;

        vector<int> indegree(v, 0);
        unordered_map<int, vector<int>> adj;

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        BFS(adj, indegree, result, v);

        return result;
    }
};

//using DFS and stack
class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recVisited, stack<int>& st){
        visited[u] = true;
        recVisited[u] = true;

        for(auto &v: adj[u]){
            if(visited[v] && recVisited[v]){
                return true;
            }else{
                if(!visited[v]){
                    if(DFS(adj, v, visited, recVisited, st)){
                        return true;
                    }
                }
            }
        }
        st.push(u);
        recVisited[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //using dfs
        int v = numCourses;
        int n = prerequisites.size();

        vector<int> result;

        vector<bool> visited(v, false);
        vector<bool> recVisited(v, false);

        vector<vector<int>> adj(v, vector<int> ());

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        stack<int> st;
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                if(DFS(adj, u, visited, recVisited, st)){
                    return {};
                };
            }
        }

        while(!st.empty()){
            int u = st.top();
            st.pop();

            result.push_back(u);
        }

        return result;
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>> prerequisites(n, vector<int> (2));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<2; j++){
            cin>>prerequisites[i][j];
        }
    }

    Solution obj;

    vector<int> result = obj.findOrder(n, prerequisites);

    for(auto &it: result){
        cout<<it<<" ";
    }

    return 0;
}