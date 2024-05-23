//for Ascending Order
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<= pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot && j>=low){
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low< high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quick_sort(vector<int> &arr,int n){
    qs(arr, 0, n-1);
    return arr;
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

    vector<int> arr = { 3, 9, 4,1};
    int n = arr.size();

    vector<int> result= quick_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}





//for Descending order
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]>= pivot && i<=high){
            i++;
        }
        while(arr[j]<pivot && j>=low){
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low< high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quick_sort(vector<int> &arr,int n){
    qs(arr, 0, n-1);
    return arr;
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

    vector<int> arr = { 3, 9, 4,1};
    int n = arr.size();

    vector<int> result= quick_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}