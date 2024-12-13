#include<bits/stdc++.h>
using namespace std;

/*
//concept Behind the solution:
The idea is based on the observation that whenever two ants collide and reverse their
directions, then it is same as if there was no collision and they continue moving in their 
original paths. This is because both ants move at the same speed and their collision is 
same as passing through each other.
If one ant is moving left and another is moving right, upon collision, they both switch 
directions but their distance to the nearest end of the plank remains unchanged. 
Therefore, the time it takes for each ant to fall off the plank is independent on the 
collisions. Now, we can simply calculate the time to fall off the plank(without collisions)
for each ant and the maximum time among all ants will be the final result.
*/

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int result = 0;
        
        for(auto it: left){
            result = max(result, it);
        }
        
        for(auto it: right){
            result = max(result, n - it);
        }
        
        return result;
    }
};

int main(){
    Solution obj;
    int n = 7;
    vector<int> left = {0, 1, 2, 3, 4, 5, 6};
    vector<int> right = {1, 2, 3, 4, 5, 6, 7};
    cout<<obj.getLastMoment(n, left, right)<<endl;
    return 0;
}