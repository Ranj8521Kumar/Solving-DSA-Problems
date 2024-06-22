#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    unordered_set<int> st;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int startingNo = it;

            while (st.find(startingNo + 1) != st.end())
            {
                startingNo += 1;
                count = count + 1;
            }

            longest = max(longest, count);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int result = longestConsecutive(nums);
    cout<<result;
    return 0;
}