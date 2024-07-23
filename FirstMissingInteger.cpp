#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    
    for(int i = 0; i<n; i++){
        while(A[i]>0 && A[i]<=n && A[i] != A[A[i]-1]){
            swap(A[i], A[A[i]-1]);
        }
    }
    
    for(int i = 0; i<n; i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
    
    return n+1;
}

int firstMissInteger(vector<int> &A){
    int n = A.size();
    for(int i = 1; i<=n; i++){
        bool isPresent = true;
        for(int j = 0; j<n; j++){
            if(A[j]==i){
                isPresent = false;
                break;
            }
        }
        if(isPresent){
            return i;
        }
    }
    return n+1;
}


int main()
{
    vector<int> A = {1,2,0};
    cout<<firstMissingPositive(A);
    cout<<firstMissInteger(A);
    return 0;
}