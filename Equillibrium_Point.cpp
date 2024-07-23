#include <iostream>
#include <vector>

using namespace std;

int equilibriumPoint(vector<long long> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 1;

    long long totalSum = 0;
    for (auto it : arr)
    {
        totalSum += it;
    }

    long long leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum -= arr[i];
        if (leftSum == totalSum)
        {
            return (i + 1);
        }
        leftSum += arr[i];
    }

    return -1;
}

int main()
{
    vector<long long> arr = {1, 3, 5, 2, 2};
    int result = equilibriumPoint(arr);
    cout << "Equilibrium Point: " << result << endl;

    return 0;
}
