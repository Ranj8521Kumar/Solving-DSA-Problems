#include<bits/stdc++.h>
using namespace std;

void reverseArray(int i, vector<int> &arr, int n){

    if(i>=n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseArray(i+1, arr, n);
}

int main()
{
    vector<int> arr = {2, 5, 8, 4, 1};
    int n = arr.size();

    reverseArray(0, arr, n);

    for(auto i: arr){
        cout<<i<<" ";
    }
    
    return 0;
}