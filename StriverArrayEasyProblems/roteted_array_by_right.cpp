// #include<bits/stdc++.h>
// using namespace std;

// void rotateArrayByRight(int arr[], int n, int k){
//     k%=n;
//     int temp[n];
//     for (int i = n-k; i < n; i++)
//     {
//         temp[i-n+k] = arr[i];
//     }

//     for (int i = n-k-1; i >=0; i--)
//     {
//         arr[i+k] = arr[i];
//     }

//     for (int i = 0; i < k; i++)
//     {
//         arr[i]= temp[i];
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7};
//     int k;
//     cin>>k;
//     int n = sizeof(arr)/sizeof(arr[0]);
//     rotateArrayByRight(arr, n, k);
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// //Second method
// #include<bits/stdc++.h>
// using namespace std;

// void reverseArray(int arr[], int start, int end){
//     while (start<=end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }

// void rotateArrayByRight(int arr[], int n, int k){
//     k = k%n;

//     reverseArray(arr, n-k, n-1);
//     reverseArray(arr, 0, n-k-1);
//     reverseArray(arr, 0, n-1);
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7};
//     int k;
//     cin>>k;
//     int n = sizeof(arr)/sizeof(arr[0]);
//     rotateArrayByRight(arr, n, k);
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


//Third method
#include<bits/stdc++.h>
using namespace std;

void rotateArrayByRight(int arr[], int n, int k){
    k = k%n;

    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i+k)%n] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k;
    cin>>k;
    int n = sizeof(arr)/sizeof(arr[0]);
    rotateArrayByRight(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}