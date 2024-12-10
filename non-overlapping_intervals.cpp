#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a,
        const vector<int>& b){
            return a[1]<b[1];
        });
        
        int end = intervals[0][1];
        int removalCount = 0;
        
        for(int i = 1; i<n; i++){
            if(intervals[i][0] < end){
                removalCount++;
            }else{
                end = intervals[i][1];
            }
        }
        
        return removalCount;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << obj.eraseOverlapIntervals(intervals) << endl;
    return 0;
}