#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(int n, int arr[]) {
    vector<int> result;
    int max = arr[n - 1];
    result.push_back(max);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= max) {
            max = arr[i];
            result.push_back(max);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int nums[] = {3, 2, 4};
    vector<int> result = leaders(3,nums);
    for(int it: result){
        cout<<it<<" ";
    }
    return 0;
}