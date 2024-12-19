#include<bits/stdc++.h>
using namespace std;

//using BFS and queue or khan's algorithm
class Solution {
public:
//thought process:
    //since for (a, b) => if I want to complete course a then first we have to complete b, means b->a, that is the meaninig of topological sort, 

    //let's take an example that (a, b) and (b, a) => there is a cycle in the graph for this, means completion of cource a is dependent of cource b and completion of course b is dependent on course a, so if cycle detected then we  can not finish all the course,

    //ApProach: Khan's Algorithm(cycle detection using BFS)

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int n = prerequisites.size();

        //Making Adjancy List
        vector<vector<int>> adj(v, vector<int> ());

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        //Detecting cycle using Khan's Algorithm

        //calculate indegree
        vector<int> indegree(v, 0);
        for(int u = 0; u<v; u++){
            for(auto &v: adj[u]){
                indegree[v]++;
            }
        }

        //push in the queue of indegree zero
        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
            }
        }

        //simple BFS
        int count = 0; //number of vertices in the topological sort

        while(!que.empty()){
            int u  = que.front();
            que.pop();
            count++;

            for(auto &v: adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        if(count != v){ //cycle detected
            return false;
        }

        return true;
    }
};

//using DFS and stack
class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recVisited){
        visited[u] = true;
        recVisited[u] = true;

        for(auto &v: adj[u]){
            if(visited[v] && recVisited[v]){
                return true;
            }else{
                if(!visited[v]){
                    if(DFS(adj, v, visited, recVisited)){
                        return true;
                    }
                }
            }
        }

        recVisited[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int n = prerequisites.size();

        vector<bool> visited(v, false);
        vector<bool> recVisited(v, false);

        //Making Adjancy List
        vector<vector<int>> adj(v, vector<int> ());

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                if(DFS(adj, u, visited, recVisited)){
                    return false;//for cycle detected then return false
                }
            }
        }

        return true;//cycle is not detected

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

    cout<<obj.canFinish(n, prerequisites)<<endl;

    return 0;
}