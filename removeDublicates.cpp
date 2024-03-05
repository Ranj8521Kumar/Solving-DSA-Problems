#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romoveDuplicates(vector<int> &arr)
    {
        int i = 0;
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[i] != arr[j])
            {
                i++;
                arr[i]=arr[j];
            }
        }
        return i+1;
    }
};

int main()
{
    vector<int> arr={1,1,2,2,2,3,3};
    Solution obj;
    int x=obj.romoveDuplicates(arr);
    cout<<"The array after removing Duplicates: ";
    for (int i = 0; i < x; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}