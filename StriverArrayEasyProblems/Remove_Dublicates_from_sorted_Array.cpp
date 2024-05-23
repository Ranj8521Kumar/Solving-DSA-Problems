#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;//return unique elements
}

int main()
{
    vector<int> arr = {1,1,2,3,3,4};
    cout<<removeDuplicates(arr);
    return 0;
}