#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &v)
{
    int count = 0;
    int el;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = v[i];
        }
        else if (v[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el)
        {
            count1++;
        }
    }

    if (count1 > (n / 2))
    {
        return el;
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int result = majorityElement(nums);
    cout<<result;
    return 0;
}