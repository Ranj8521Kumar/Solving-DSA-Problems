#include <bits/stdc++.h>
using namespace std;

int LDS(vector<int> &arr){
    // Write your code here.
    int n = arr.size();

    vector<int> LDSA(n, 1);
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                LDSA[i] = max(LDSA[i], LDSA[j] + 1);
            }
        }
    }
    return *max_element(LDSA.begin(), LDSA.end());
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Decreasing Subsequence is " << LDS(arr) << endl;
    return 0;
}