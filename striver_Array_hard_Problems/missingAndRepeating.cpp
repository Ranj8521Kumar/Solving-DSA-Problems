#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int N)
    {
        long long n = (long long)N;
        long long Sn = n * (n + 1) / 2;
        long long S2n = n * (n + 1) * (2 * n + 1) / 6;

        long long S = 0;
        long long S2 = 0;

        for (int i = 0; i < n; i++)
        {
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }

        long long val1 = Sn - S;
        long long val2 = S2n - S2;
        val2 = val2 / val1;

        long long missingNumber = (val2 + val1) / 2;
        long long repeatingNumber = missingNumber - val1;

        return {(int)repeatingNumber, (int)missingNumber};
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {4, 3, 6, 2, 1, 1};
    vector<int> result1 = sol.findTwoElement(arr1, arr1.size());
    cout << "Repeating number: " << result1[0] << ", Missing number: " << result1[1] << endl;

    vector<int> arr2 = {4, 3, 6, 2, 1, 6};
    vector<int> result2 = sol.findTwoElement(arr2, arr2.size());
    cout << "Repeating number: " << result2[0] << ", Missing number: " << result2[1] << endl;

    vector<int> arr3 = {7, 3, 4, 5, 5, 6, 2};
    vector<int> result3 = sol.findTwoElement(arr3, arr3.size());
    cout << "Repeating number: " << result3[0] << ", Missing number: " << result3[1] << endl;

    return 0;
}
