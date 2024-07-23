#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long countSubarray(int arr[], int n, int k)
    {
        long long countLessEqualK = 0;
        int i = 0;

        while (i < n)
        {
            if (arr[i] > k)
            {
                i++;
                continue;
            }

            long long length = 0;
            while (i < n && arr[i] <= k)
            {
                i++;
                length++;
            }

            countLessEqualK += (length * (length + 1)) / 2;
        }

        long long totalSubarrays = ((long long)n * (n + 1)) / 2;
        return totalSubarrays - countLessEqualK;
    }
};


int main()
{
    Solution sol;
    int arr1[] = {3, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    cout << sol.countSubarray(arr1, n1, k1) << endl;

    return 0;
}
