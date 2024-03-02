#include<bits/stdc++.h>
using namespace std;

int linear_search_array(int arr[], int n, int search_data){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==search_data){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int d=linear_search_array(arr, n, 4);
    cout<<"Found at "<<d<<"th index."<<endl;
    return 0;
}