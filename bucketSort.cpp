#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void bucketSort(vector<float>& arr){
            int  n  = arr.size();

            vector<vector<float>> buckets(n);
            for(auto it: arr){
                int index = it*n;
                buckets[index].push_back(it);
            }

            int j = 0;
            for(auto &bucket: buckets){
                sort(bucket.begin(), bucket.end());
                int i = 0;
                for(auto &val: bucket){
                    arr[j++] = val;
                }
            }
        }
};

int main() {
    Solution obj;
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    obj.bucketSort(arr);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}