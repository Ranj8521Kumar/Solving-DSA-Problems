//bubble_sort using recursion
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n ){
if(n<=1){
    return;
}

int didSwap = 0;
    int i = 0;
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
            didSwap = 1;
        }
        i++;
    }
if(didSwap == 0){
    return;
}
    cout<<"hello"<<endl;

    bubble_sort(arr, n-1);
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

    int arr[] = {9,8,7,6,5,4,3,2,1};
    // int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}