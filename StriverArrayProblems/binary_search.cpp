// #include <bits/stdc++.h>
// using namespace std;

// int searchInSorted(int arr[], int N, int K)
// {
//     int low = 0;
//     int high = N - 1;
//     for (int i = low; i <= high; i++)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr[i] > K)
//         {
//             high = mid;
//         }
//         else if (arr[i] < K)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             return 1;
//         }
//     }

//     return -1;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7};
//     int K = 2;
//     int n = 7;
//     cout<<searchInSorted(arr, 7, 2);
//     return 0;
// }


//Second Method
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int K){
    if(low>high){
        return -1;
    }

    int mid  = low + (high - low)/2;

    if(arr[mid]==K){
        return 1;
    }else if(arr[mid]<K){
        return binarySearch(arr, mid+1, high, K);
    }else{
        return binarySearch(arr, low, mid-1, K);
    }
}

int searchInSorted(int arr[], int N, int K)
{
    int low = 0;
    int high = N - 1;
    binarySearch(arr, low, high, K);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int K = 2;
    int n = 7;
    cout<<searchInSorted(arr, 7, 2);
    return 0;
}