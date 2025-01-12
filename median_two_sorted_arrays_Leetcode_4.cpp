#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedArray;

        int i = 0; int j = 0;
        int m = nums1.size();
        int n = nums2.size();

        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                sortedArray.push_back(nums1[i++]);
            }else{
                sortedArray.push_back(nums2[j++]);
            }
        }

        while(i<m){
            sortedArray.push_back(nums1[i++]);
        }

        while(j<n){
            sortedArray.push_back(nums2[j++]);
        }

        if((m+n) % 2 != 0){
            return sortedArray[(m+n)/2];
        }else{
            return ((double)sortedArray[(m+n)/2 - 1] + (double)sortedArray[(m+n)/2])/2;
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution obj;
    cout<<obj.findMedianSortedArrays(nums1, nums2);
    return 0;
}