// #include <bits/stdc++.h>
// using namespace std;

// int findSingleNumber(vector<int> &nums)
// {
//     int count = 0;
//     int j = 0;
//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[j] == nums[i])
//         {
//             count++;
//         }
//         else
//         {
//             if (count > 1)
//             {
//                 count = 1;
//             }
//             else
//             {
//                 return nums[j];
//             }
//             j = i;
//         }
//     }
//     return nums[j];
// }

// int main()
// {
//     vector<int> arr = {1, 0, 0, 1, 2};
//     cout << findSingleNumber(arr);
//     return 0;
// }



// //second method
// #include <bits/stdc++.h>
// using namespace std;

// int findSingleNumber(vector<int> &nums)
// {
    
//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < nums.size(); i+=2)
//     {
//         if(i==nums.size()-1||nums[i]!=nums[i+1]){
//             return nums[i];
//         }
//     }
//     return -1;
// }

// int main()
// {
//     vector<int> arr = {1, 0, 0, 1, 2};
//     cout << findSingleNumber(arr);
//     return 0;
// }


// //third method
// #include <bits/stdc++.h>
// using namespace std;

// int findSingleNumber(vector<int> &nums)
// {
//     int maxi = nums[0];
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, nums[i]);
//     }

//     int hash[maxi+1] = {0}; // vector<int> hash(maxi + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         hash[nums[i]]++;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if(hash[nums[i]]==1){
//             return nums[i];
//         }
//     }
    
//     return -1;
// }

// int main()
// {
//     vector<int> arr = {1, 0, 0, 1, 2};
//     cout << findSingleNumber(arr);
//     return 0;
// }



//fourth method, we can easily solve this question using xor operation
#include <bits/stdc++.h>
using namespace std;

int findSingleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr^nums[i];
    }
    
    
    return xorr;
}

int main()
{
    vector<int> arr = {1, 0, 0, 1, 2};
    cout << findSingleNumber(arr);
    return 0;
}