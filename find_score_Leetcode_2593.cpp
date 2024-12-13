#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        vector<bool> marked(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i = 0; i<n; i++){
            minHeap.push({nums[i], i});
        }

        long long score = 0;

        while(!minHeap.empty()){
            auto [value, index] = minHeap.top();
            minHeap.pop();

            if(!marked[index]){
                marked[index] = true;
                score += value;

                if(index > 0){
                    marked[index-1] = true;
                }

                if(index < n-1){
                    marked[index+1] = true;
                }
            }
        }

        return score;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<obj.findScore(nums)<<endl;
    return 0;
}