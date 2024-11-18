#include<bits/stdc++.h>
using namespace std;

//function to sort the nearly sorted array with at most k distance with in-place sorting
vector<int> sortKSortedArray(vector<int> arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result;

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            result.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}
//write the main function
int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int n = arr.size();
    int k = 3;

    vector<int> result = sortKSortedArray(arr, n, k);

    for(auto it : result) {
        cout << it << " ";
    }

    return 0;
}