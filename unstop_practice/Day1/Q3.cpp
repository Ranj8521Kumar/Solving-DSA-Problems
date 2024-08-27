#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> gain(n);

    for (int i = 0; i < n; i++)
    {
        cin >> gain[i];
    }

    int highestAlt = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += gain[i];
        highestAlt = max(sum, highestAlt);
    }

    cout << highestAlt << endl;

    return 0;
}