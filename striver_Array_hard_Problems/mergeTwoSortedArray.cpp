// #include <iostream>
// using namespace std;

// //sort without an extra space

// class Solution {
// private:
//     void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
//         if (arr1[ind1] > arr2[ind2]) {
//             swap(arr1[ind1], arr2[ind2]);
//         }
//     }

// public:
//     void merge(long long arr1[], long long arr2[], int n, int m) {
//         int len = n + m;
//         int gap = (len / 2) + (len % 2);

//         while (gap > 0) {
//             int left = 0;
//             int right = left + gap;

//             while (right < n + m) {
//                 if (left < n && right < n) {
//                     swapIfGreater(arr1, arr1, left, right);
//                 } else if (left < n && right >= n) {
//                     swapIfGreater(arr1, arr2, left, right - n);
//                 } else if (left >= n && right >= n) {
//                     swapIfGreater(arr2, arr2, left - n, right - n);
//                 }

//                 left++;
//                 right++;
//             }

//             if (gap == 1) {
//                 break;
//             }
//             gap = (gap / 2) + (gap % 2);
//         }
//     }
// };

// int main() {
//     long long arr1[] = {1, 3, 5, 7};
//     long long arr2[] = {0, 2, 6, 8, 9};
//     int n = sizeof(arr1) / sizeof(arr1[0]);
//     int m = sizeof(arr2) / sizeof(arr2[0]);

//     Solution sol;
//     sol.merge(arr1, arr2, n, m);

//     cout << "Merged array arr1: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr1[i] << " ";
//     }
//     cout << endl;

//     cout << "Merged array arr2: ";
//     for (int i = 0; i < m; i++) {
//         cout << arr2[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


// //sort without an extra space approach 2
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b) {
//     int m = a.size();
//     int n = b.size();
    
//     int i = 0; 
//     int j = 0; 
    
//     while (i < m && j < n) {
//         if (a[i] <= b[j]) {
//             i++;
//         } else {
//             swap(a[i], b[j]);
//             sort(a.begin(), a.begin() + m);
//             sort(b.begin(), b.end());
//             i++;
//         }
//     }
// }

// int main() {
//     vector<long long> a = {1, 3, 5, 7};
//     vector<long long> b = {2, 4, 6, 8, 9};

//     mergeTwoSortedArraysWithoutExtraSpace(a, b);

//     cout << "Merged Array a: ";
//     for (auto num : a) {
//         cout << num << " ";
//     }
//     cout << endl;

//     cout << "Merged Array b: ";
//     for (auto num : b) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }


//sort using an extra space
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int left = 0; 
        int right = 0;

        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                nums3.push_back(nums1[left++]); 
            } else {
                nums3.push_back(nums2[right++]); 
            }
        }

        while (left < m) {
            nums3.push_back(nums1[left++]);
        }

        while (right < n) {
            nums3.push_back(nums2[right++]);
        }

        for (int i = 0; i < nums3.size(); ++i) {
            nums1[i] = nums3[i];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
