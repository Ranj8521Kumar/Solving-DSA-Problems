#include <bits/stdc++.h>
using namespace std;

void frequencyCount(vector<int> &arr, int N, int P)
{
    // convert to 0 - based indexing
    for (int i = 0; i < N; i++)
    {
        arr[i]--;
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] % P < N)
        {
            arr[arr[i] % P] += P;
        }
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] /= P;
    }
}

int main()
{
    vector<int> arr = {8, 9};
    int P= 9;
    int N = arr.size();
    frequencyCount(arr, N,  P);
    for(int i:arr){
        cout<<arr[i]<<" ";
    }
    return 0;
}