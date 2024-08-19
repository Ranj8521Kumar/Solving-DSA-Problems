// First Approach
//  #include <iostream>
//  #include <vector>

// using namespace std;

// class Solution {
// public:
//     int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
//         int n1 = arr1.size();
//         int n2 = arr2.size();
//         vector<int> arr;

//         int i = 0;
//         int j = 0;

//         while(i < n1 && j < n2) {
//             if(arr1[i] <= arr2[j]) {
//                 arr.push_back(arr1[i]);
//                 i++;
//             } else {
//                 arr.push_back(arr2[j]);
//                 j++;
//             }
//         }

//         while(i < n1) {
//             arr.push_back(arr1[i]);
//             i++;
//         }

//         while(j < n2) {
//             arr.push_back(arr2[j]);
//             j++;
//         }

//         return arr[k-1];
//     }
// };

// int main() {
//     Solution solution;
//     vector<int> arr1 = {1, 3, 5};
//     vector<int> arr2 = {2, 4, 6};
//     int k = 4;

//     int result = solution.kthElement(k, arr1, arr2);
//     cout << "The " << k << "th element is: " << result << endl;

//     return 0;
// }

// Second Approach

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();

        int i = 0;
        int j = 0;
        int idx = 0;

        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                if (idx == k - 1)
                {
                    return arr1[i];
                }
                i++;
            }
            else
            {
                if (idx == k - 1)
                {
                    return arr2[j];
                }
                j++;
            }
            idx++;
        }

        while (i < n1)
        {
            if (idx == k - 1)
            {
                return arr1[i];
            }
            i++;
            idx++;
        }

        while (j < n2)
        {
            if (idx == k - 1)
            {
                return arr2[j];
            }
            j++;
            idx++;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    int k = 4;

    int result = solution.kthElement(k, arr1, arr2);
    cout << "The " << k << "th element is: " << result << endl;

    return 0;
}
