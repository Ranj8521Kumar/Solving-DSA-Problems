#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    long long sumA = 0;
    long long sumSqA = 0;

    for (int i = 0; i < n; i++)
    {
        sumA += (long long)A[i];
        sumSqA += ((long long)A[i] * (long long)A[i]);
    }

    long long ESumA = (long long)n * (n + 1) / 2;
    long long ESumSqA = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long diff = ESumA - sumA;
    long long diffSq = ESumSqA - sumSqA;

    long long sum = (diffSq / diff);

    long long missingNo = (diff + sum) / 2;
    long long repeatingNo = missingNo - diff;

    return {(int)repeatingNo, (int)missingNo};
}

int main()
{
    vector<int> arr = {3, 1, 2, 5, 3};
    vector<int> result = repeatedNumber(arr);
    for(int it: result){
        cout<<it<<" ";
    }
    return 0;
}