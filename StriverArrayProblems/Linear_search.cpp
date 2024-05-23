#include<bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n, int k){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==k){
            return 1;
        }
    }

    return -1;
    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int K = 2;
    int n = 7;
    cout<<linearSearch(arr, 7, 2);
    return 0;
}