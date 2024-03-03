#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int target)
{

    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left +(right-left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Target value is at " << binary_search(arr, n, 7) << "th index." << endl;
    return 0;
}