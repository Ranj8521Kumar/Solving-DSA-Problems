// #include<bits/stdc++.h>
// using namespace std;

// void moveZerosAtEnd(int arr[], int n){
//     int count = 0;
//     int j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]==0){
//             count++;
//         }else{
//             arr[j]=arr[i];
//             j++;
//         }
//     }


//     for (int i = j; i < n; i++)
//     {
//         arr[i] = 0;
//     }
    
    
// }



// int main()
// {
//     int arr[] = {1, 0, 3, 0, 5, 0, 7};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     moveZerosAtEnd(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return a;

    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}


int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    int n = arr.size();
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}

