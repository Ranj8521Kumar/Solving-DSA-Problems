#include<bits/stdc++.h>
using namespace std;

//first method
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxLeft = arr[0]; // Tracks the maximum in the current chunk
        int count = 0;

        for(int i = 0; i<n; i++){
            maxLeft = max(maxLeft, arr[i]);
            if(maxLeft == i){
                count++;
            }
        }

        return count;
    }
};

//second method
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int chunk = 0;
        int cummulativeSum = 0;
        int sum = 0;

        for(int i = 0; i<n; i++){
            cummulativeSum += i;

            sum += arr[i];

            if(cummulativeSum == sum){
                chunk++;
            }
        }

        return chunk;
    }
};

//third method
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> suffixMin(n, INT_MAX);
        int minValue = INT_MAX;

        for(int i = n-1; i>=0;  i--){
            minValue = min(minValue, arr[i]);
            suffixMin[i] =  minValue;
        }

        int maxValue;
        int count = 0;
        
        for(int i = 0; i<n; i++){
            maxValue = (i == 0)?-1:max(maxValue, arr[i-1]);
            if(maxValue  <= suffixMin[i]){
                count++;
            }
        }

        return count;
    }
};

//Driver code
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    Solution obj;
    cout<<obj.maxChunksToSorted(arr)<<endl;

    return 0;
}