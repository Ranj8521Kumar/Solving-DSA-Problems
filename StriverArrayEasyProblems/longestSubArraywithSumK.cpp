// first method
// #include <bits/stdc++.h>
// using namespace std;

// int lenOfLongSubarr(int a[], int n, int k)
// {
//     long long currentSum = 0;
//     int maxLen = 0;
//     unordered_map<long long, int> prefixSumIndices;
//     for (int i = 0; i < n; i++)
//     {
//         currentSum += a[i];

//         if (currentSum == k)
//         {
//             maxLen = max(maxLen, i + 1);
//         }

//         long long rem = currentSum - k;

//         if (prefixSumIndices.find(rem) != prefixSumIndices.end())
//         {
//             int len = i - prefixSumIndices[rem];
//             maxLen = max(maxLen, len);
//         }

//         if (prefixSumIndices.find(currentSum) == prefixSumIndices.end())
//         {
//             prefixSumIndices[currentSum] = i;
//         }
//     }
//     return maxLen;
// }

// int main()
// {
//     int arr[] = {1,2,3,1,1,1,1,4,2,3};
//     int k = 3;
//     int n = 10;
//     cout<<lenOfLongSubarr(arr, 10, 3);
//     return 0;
// }

// second Method
// #include <bits/stdc++.h>
// using namespace std;

// int longestSubarrayWithSumK(int a[], int n, long long k)
// {
//     int left = 0;
//     int right = 0;
//     int maxLen = 0;
//     long long sum = a[0];
//     while (right < n)
//     {

//         if (left <= right && sum > k)
//         {
//             sum = sum - a[left];
//             left++;
//         }

//         if (sum == k)
//         {
//             maxLen = max(maxLen, right - left + 1);
//         }

//         right++;
//         if (right < n)
//         {
//             sum = sum + a[right];
//         }
//     }
//     return maxLen;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     int k = 3;
//     int n = 10;
//     cout << longestSubarrayWithSumK(arr, 10, 3);
//     return 0;
// }

// //third method
// #include <bits/stdc++.h>
// using namespace std;

// int longestSubarrayWithSumK(int a[], int n, long long k)
// {
//     int maxLen = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             long long sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum = sum + a[k];
//             }
//             if(sum==k){
//                 maxLen = max(maxLen, j-i+1);
//             }
            
//         }
        
//     }
//     return maxLen;
    
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     int k = 3;
//     int n = 10;
//     cout << longestSubarrayWithSumK(arr, 10, 3);
//     return 0;
// }

//fourth method
//third method
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(int a[], int n, long long k)
{
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if(sum==k){
                maxLen = max(maxLen, j-i+1);
            }
        }
        
    }
    return maxLen;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k = 3;
    int n = 10;
    cout << longestSubarrayWithSumK(arr, 10, 3);
    return 0;
}