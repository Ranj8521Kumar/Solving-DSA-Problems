#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotateTheBox(vector<vector<char>>& box) {
            int m = box.size();
            int n = box[0].size();

            vector<vector<char>> result(n, vector<char>(m));
            
            for(auto &row: box){
                int j = n-1; //empty cell
                for(int i = n-1; i>=0; i--){
                    if(row[i]=='*'){
                        j=n-1;
                    }else if(row[i]=='#'){
                        swap(row[i],row[j]);
                        j--;
                    }
                }
            }

            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    result[i][m-1-i] = box[i][j];
                }
            }
        }
};

int main() {
    Solution obj;
    vector<vector<char>> box = {{'#','.','#'}};
    obj.rotateTheBox(box);
    for(auto &row: box){
        for(auto &it: row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}