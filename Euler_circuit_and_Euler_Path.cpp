#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void DFS(vector<int> adj[], int u, vector<int>& visited) {
        visited[u] = true;
        
        for (auto &v: adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }

    int isEulerCircuit(int v, vector<int> adj[]) {
        vector<int> degree(v, 0);
        for (int u = 0; u < v; u++) {
            for (auto &vec: adj[u]) {
                degree[u]++;
            }
        }
        
        vector<int> visited(v, false);
        for (int u = 0; u < v; u++) {
            if (degree[u] != 0) {
                DFS(adj, u, visited);
                break;
            }
        }
        
        for (int u = 0; u < v; u++) {
            if (degree[u] != 0 && !visited[u]) {
                return 0;
            }
        }
        
        int countOddDegree = 0;
        for (auto &it: degree) {
            if (it % 2 != 0) {
                countOddDegree++;
            }
        }
        
        if (countOddDegree == 0) {
            return 2;
        } else if (countOddDegree == 2) {
            return 1;
        } else {
            return 0;
        }
    }
};

int main() {
    int v = 5;
    vector<int> adj[v];
    
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    Solution sol;
    int result = sol.isEulerCircuit(v, adj);
    
    if (result == 0) {
        cout << "Graph is not Eulerian" << endl;
    } else if (result == 1) {
        cout << "Graph has an Euler Path" << endl;
    } else if (result == 2) {
        cout << "Graph has an Euler Circuit" << endl;
    }
    
    return 0;
}