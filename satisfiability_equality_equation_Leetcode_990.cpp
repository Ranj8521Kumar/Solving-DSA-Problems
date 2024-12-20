#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int parent_u, int parent_v, vector<int>& parent, vector<int>& rank){
        if(rank[parent_u] == rank[parent_v]){
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else{
            parent[parent_u] = parent_v;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        //using dsu(disjoint set union-find)

        int n = equations.size();
        vector<int> parent(26);
        vector<int> rank(26,  0);

        for(int i = 0; i<26; i++){
            parent[i] = i;
        }

        for(auto &vec: equations){
            int parent_u = find(vec[0] - 'a', parent);
            int parent_v = find(vec[3] - 'a', parent);
            if(vec[1] == '='){
                unionSet(parent_u, parent_v, parent, rank);
            }
        }


        for(auto &vec: equations){
            int parent_u = find(vec[0] - 'a', parent);
            int parent_v = find(vec[3] - 'a', parent);
            if(vec[1] == '!'){
                if(parent_u == parent_v){
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

    vector<string> equations(n);

    for(int i = 0; i<n; i++){
        cin>>equations[i];
    }

    Solution obj;

    cout<<obj.equationsPossible(equations)<<endl;

    return 0;
}