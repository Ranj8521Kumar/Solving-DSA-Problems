// #include<bits/stdc++.h>
// using namespace std;

// int findMaxConsecutiveOnes(vector<int>& nums) {
//         int count = 0;
//         vector<int> arr;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 1) {
//                 count++;
//             } else {
//                 arr.push_back(count);
//                 count = 0;
//             }
//         }
//         arr.push_back(count);

//         int maxCount = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             if (arr[i] > maxCount) {
//                 maxCount = arr[i];
//             }
//         }

//         return maxCount;
//     }

// int main()
// {
//     vector<int> arr = {1,1,0,1,1,1};
//     cout<<findMaxConsecutiveOnes(arr);
//     return 0;
// }

// second method
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            if (count > maxCount)
            {
                maxCount = count;
            }
            count = 0;
        }
    }
    if (count > maxCount)
    {
        maxCount = count;
    }
    return maxCount;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(arr);
    return 0;
}