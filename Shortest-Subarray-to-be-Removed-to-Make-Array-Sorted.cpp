// write code for Shortest Subarray to be Removed to Make Array Sorted

#include<bits/stdc++.h>
using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;
    while(left + 1 < n && arr[left] <= arr[left + 1]) {
        left++;
    }
    if(left == n - 1) {
        return 0;
    }
    while(right > 0 && arr[right] >= arr[right - 1]) {
        right--;
    }
    int result = min(n - left - 1, right);
    int i = 0, j = right;
    while(i <= left && j < n) {
        if(arr[j] >= arr[i]) {
            result = min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }
    return result;
}

//write the main function
int main() {
    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    cout << findLengthOfShortestSubarray(arr) << endl;
    return 0;
}