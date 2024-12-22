#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int v = n;

        vector<vector<pair<int, int>>> adj(v+1);
        for(auto &time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        vector<int> delay(v+1, INT_MAX);
        delay[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            for(auto &v: adj[u.second]){
                int node = v.first;
                int t = v.second;

                int updatedDelay = u.first + t;
                if(updatedDelay < delay[node]){
                    delay[node] = updatedDelay;
                    pq.push({updatedDelay, node});
                }
            }
        }

        int minTime = INT_MIN;
        for(int u = 1; u<=v; u++){
            if(delay[u] == INT_MAX){
                return -1;
            }

            minTime = max(minTime, delay[u]);
        }

        return minTime;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;

    cout << sol.networkDelayTime(times, n, k) << endl;

    return 0;
}