#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        
        //if no edge  between vertices then make it maximum weight
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 10000;
                }
            }
        }
        
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        
        //again for no edge make it -1
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 10000){
                    mat[i][j] = -1;
                }
            }
        }
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>> mat(n, vector<int> (n));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    Solution s;
    s.shortestDistance(mat);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}