#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k)
{
    int count = 0;
    unordered_map<int, int> sumCount;
    sumCount[0] = 1;
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sumCount.find(sum - k) != sumCount.end())
        {
            count = count + sumCount[sum - k];
        }

        sumCount[sum]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {3, 2, 1};
    int result = subarraySum(nums, 3);
    cout<<result;
    return 0;
}