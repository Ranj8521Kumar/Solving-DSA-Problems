#include<bits/stdc++.h>
using namespace std;

//first Approach: Brute Force Approach: Time Complexity: O(n^2): Time Limit Exceeded
// class Solution {
// public:
// //Brute force Approach
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int n = values.size();
//         int maxScore = INT_MIN;

//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 int score = (values[i] + i) + (values[j] - j);
//                 maxScore = max(maxScore, score);
//             }
//         }

//         return maxScore;
//     }
// };

// //Second Approach: Optimal Approach: Time Complexity: O(n): Space Complexity: O(n)
// class Solution {
// public:
// //Optimal Approach
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int n = values.size();

//         vector<int> maxScoreTill(n);//store the maximum value till of valuse[i] + i till ith index
//         maxScoreTill[0] = values[0];
//         int temp = maxScoreTill[0];

//         for(int i = 1; i<n; i++){
//             int value = values[i] + i;
//             temp = max(temp, value);
//             maxScoreTill[i] = temp;
//         }

//         int maxScore = maxScoreTill[0];

//         for(int j = 1; j<n; j++){
//             int value = values[j] - j;
//             maxScore = max(maxScore, value + maxScoreTill[j-1]);
//         }

//         return maxScore;
//     }
// };

// //Third Approach: Optimal Approach: Time Complexity: O(n): Space Complexity: O(1)
// class Solution {
// public:
// //Optimal Approach
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int n = values.size();
//         int maxScore = INT_MIN;

//         int maxScoreTill = values[0];//store the maximum value till of valuse[i] + i till ith index
//         for(int i = 1; i<n; i++){
//             maxScoreTill = max(maxScoreTill, values[i-1] + (i-1));
//             int value = values[i] - i;
            
//             maxScore = max(maxScore, maxScoreTill + value);
//         }

//         return maxScore;
//     }
// };

//Fouth Approach: Optimal Approach: Time Complexity: O(n): Space Complexity: O(n): Using Priority Queue or Max Heap
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //using maxHeap or Priority Queue
        priority_queue<int> maxHeap; //since by default prioroty queue is a max Heap
        int n = values.size();
        int maxScore = INT_MIN;

        for(int i = 1; i<n; i++){
            maxHeap.push(values[i-1] + (i-1));
            
            int maxValue =  maxHeap.top();
            maxScore = max(maxScore, maxValue + (values[i] - i));
        }

        return maxScore;
    }
};

int main(){
    Solution s;
    vector<int> values = {8,1,5,2,6};
    cout<<s.maxScoreSightseeingPair(values)<<endl;
    return 0;
}