//Brute Force Approach

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> twoSum(vector<int>& nums, int target){
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if((nums[i]+nums[j])==target){
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
    
// }

// int main()
// {
//     vector<int> nums = {4, 1, 2, 3, 1};
//     vector<int> result = twoSum(nums, 6);
//     for(int it : result){
//         cout<<it<<" ";
//     }
//     return 0;
// }



//Optimal Approach(First Type)
// #include<bits/stdc++.h>
// using namespace std;

// string read(int n, vector<int> book, int target)
// {
//     sort(book.begin(), book.end());
//     int left= 0;
//     int right = n-1;
//     while(left<right){
//         if((book[left]+book[right])==target){
//             return "YES";
//         }else if(book[left]+book[right]<target){
//             left++;
//         }else{
//             right--;
//         }
        
//     }
//     return "NO";
// }


// int main()
// {
//     vector<int> nums = {4, 1, 2, 3, 1};
//     cout<<read(5, nums, 6);
//     return 0;
// }



//Optimal Approach(Second Type)
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int num = nums[i];
            int more =  target - num;

            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }


int main()
{
    vector<int> nums = {4, 1, 2, 3, 1};
    vector<int> result = twoSum(nums, 6);
    for(int it : result){
        cout<<it<<" ";
    }
    return 0;
}

