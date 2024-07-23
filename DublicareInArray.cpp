#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int num : A)
        {
            if (num <= mid)
            {
                count++;
            }
        }

        if (count > mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {3, 4, 1, 4, 2};
    cout<<repeatedNumber(arr);
    return 0;
}