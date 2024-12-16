#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define p pair<double, int> //{gain, index}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<p> maxHeap;

        int index = 0;
        for(auto &vec: classes){
            double ratio = (double)vec[0]/vec[1];
            double updatedRatio = (double)(vec[0]+1)/(vec[1]+1);

            double delta = updatedRatio - ratio;

            maxHeap.push({delta, index});
            index++;
        }

        while(extraStudents--){
            auto curr = maxHeap.top();
            maxHeap.pop();

            int idx  = curr.second;

            classes[idx][0] += 1;
            classes[idx][1] += 1;

            double ratio = (double)classes[idx][0]/classes[idx][1];
            double updatedRatio = (double)(classes[idx][0]+1)/(classes[idx][1]+1);

            double delta = updatedRatio - ratio;

            maxHeap.push({delta, idx});
        }

        double result = 0.0;
        for(auto &vec: classes){
            result += (double)vec[0]/vec[1];
        }

        return result/n;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    cout<<obj.maxAverageRatio(classes, extraStudents)<<endl;
    return 0;
}