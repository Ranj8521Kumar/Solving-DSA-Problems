#include<bits/stdc++.h>
using namespace std;

int largest(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    return arr[n-1];
    
}

int main()
{
    int arr[]={2,5,8,9,7,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<largest(arr,n)<<" is the Largest Number."<<endl;
    return 0;
}