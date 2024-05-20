#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    
}

int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    int arr[] = {8, 7, 2, 3, 9, 4};
    // int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}