#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isSortedArray(vector<int>& arr){
            int n=arr.size();
            for (int i = 1; i < n; i++)
            {
                if(arr[i]<arr[i-1]){
                    return false;
                }
            }
            return true;
        }
};

int main()
{
    Solution obj;
    vector<int> arr = {1,2,3,5,4,6};
    if(obj.isSortedArray(arr)){
        cout<<"Given Array is Sorted."<<endl;
    }else{
        cout<<"Given Array is not Sorted."<<endl;
    }
    return 0;
}