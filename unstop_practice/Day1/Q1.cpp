#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<string> str(n);
    for(int i = 0; i<n; i++){
        cin>>str[i];
    }

    int k;
    cin>>k;

    unordered_map<string, int> mpp;

    for(auto &it: str){
        mpp[it]++;
    }

    for(auto &it: str){
        if(mpp[it] == 1){
            k--;
            if(k == 0){
                cout<<it<<endl;
                return 0;
            }
        }
    }

    return 0;
}