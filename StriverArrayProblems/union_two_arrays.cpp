// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findUnion(int arr1[], int arr2[], int m, int n)
// {
//     vector<int> result;
//     int i = 0;
//     int j = 0;
//     while (i < m && j < n)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             if (result.empty() || result.back() != arr1[i])
//             {
//                 result.push_back(arr1[i]);
//             }
//             i++;
//         }
//         else if (arr1[i] > arr2[j])
//         {
//             if (result.empty() || result.back() != arr2[j])
//             {
//                 result.push_back(arr2[j]);
//             }
//             j++;
//         }
//         else
//         {
//             if (result.empty() || result.back() != arr1[i])
//             {
//                 result.push_back(arr1[i]);
//             }
//             i++;
//             j++;
//         }
//     }
//     while (i < m)
//     {
//         if (result.empty() || result.back() != arr1[i])
//         {
//             result.push_back(arr1[i]);
//         }
//         i++;
//     }

//     while (j < n)
//     {
//         if (result.empty() || result.back() != arr2[j])
//         {
//             result.push_back(arr2[j]);
//         }
//         j++;
//     }

//     return result;
// }

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7};
//     int arr2[] = {1, 2, 3, 5, 6, 7};
//     int m = sizeof(arr1) / sizeof(arr1[0]);
//     int n = sizeof(arr2) / sizeof(arr2[0]);
//     vector<int> result = findUnion(arr1, arr2, m, n);
//     // for(int it:result){
//     //     cout<<result[it]<<" ";
//     // }

//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
//     return 0;
// }

// //second method
// //using map, Since map is sorted and unique key
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findUnion(int arr1[], int arr2[], int m, int n)
// {
//     vector<int> result;
//     map<int, int> mpp;

//     for (int i = 0; i < m; i++)
//     {
//         mpp[arr1[i]]++;
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         mpp[arr2[i]]++;
//     }

//     for(auto it:mpp){
//         result.push_back(it.first);
//     }

//     return result;
// }

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7};
//     int arr2[] = {1, 2, 3, 5, 6, 7};
//     int m = sizeof(arr1) / sizeof(arr1[0]);
//     int n = sizeof(arr2) / sizeof(arr2[0]);
//     vector<int> result = findUnion(arr1, arr2, m, n);
//     // for(int it:result){
//     //     cout<<result[it]<<" ";
//     // }

//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
//     return 0;
// }


//third method
//using set, Since set is sorted and not store duplicate value
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int m, int n)
{
    vector<int> result;
    set<int> s;

    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        s.insert(arr2[i]);
    }

    for(auto it:s){
        result.push_back(it);
    }

    return result;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {1, 2, 3, 5, 6, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> result = findUnion(arr1, arr2, m, n);
    // for(int it:result){
    //     cout<<result[it]<<" ";
    // }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}

