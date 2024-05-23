#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    int n = arr.size();
    int start = m + 1;
    int end = n - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    int m = 3;
    reverseArray(arr, m);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}