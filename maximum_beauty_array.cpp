#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         int n =  nums.size();
//         vector<pair<int, int>> intervals;

//         for(auto num: nums){
//             intervals.push_back({num - k, num + k});
//         }

//         sort(intervals.begin(), intervals.end());

//         queue<int> q;

//         int maxBeauty = 0;

//         for(auto &pair: intervals){
//             while(!q.empty() && q.front()<pair.first){
//                 q.pop();
//             }

//             q.push(pair.second);
//             maxBeauty = max(maxBeauty, (int)q.size()); //Data Type of q.size(): The size() function of a std::queue returns a value of type size_t, which is an unsigned integer type. Specifically, size_t is typically defined as an unsigned integer (e.g., unsigned int, unsigned long, etc.), and its exact size depends on the system architecture (usually 4 bytes or 8 bytes).

//         }

//         return maxBeauty;
//     }
// };



//Second Approach:
// class Solution {
//         // thought process:
//         // (x, y) => range: ((x-k, x+k), (y-k, y+k)) => for overlapping: x+k>=y-k => y<=x+2*k
// private:
//     int binarySearch(vector<int> &nums, int y){
//         int left = 0;
//         int right = nums.size() - 1;

//         int result;

//         while(left<=right){
//             int mid = left + (right - left)/2;

//             if(nums[mid]<=y){
//                 result = mid;
//                 left  = mid+1; //for farthest point from x, which satisfy the condition for y<=x+2*k
//             }else{
//                 right = mid - 1;
//             }
//         }
//         return result;
//     }


// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());

//         int maxBeauty = 0;

//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             int x = nums[i];
//             int y = x + 2*k;

//             int j = binarySearch(nums, y);

//             maxBeauty = max(maxBeauty, j - i + 1);
//         }

//         return maxBeauty;
//     }
// };

//Third Approach:
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();

        int maxBeauty = 0;

        sort(begin(nums), end(nums));

        int j = 0;

        for(int i = 0; i<n; i++){
            int x = nums[i];
            int y = x+2*k;

            while(j<n && nums[j]<=y){
                j++;
            }

            maxBeauty = max(maxBeauty, j-i);
        }

        return maxBeauty;
    }
};



int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1;
    cout << obj.maximumBeauty(nums, k) << endl;
    return 0;
}