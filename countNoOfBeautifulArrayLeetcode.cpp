#include<bits/stdc++.h>
using namespace std;

long long beautifulSubarrays(vector<int>& a) {
        int n = a.size();
        map<int, int> mpp;
        int xr = 0;
        mpp[xr]++;
        long long count = 0;
        for(int i = 0; i<n; i++){
            xr = xr^a[i];

            int x = xr;
            count +=(long long) mpp[x];

            mpp[xr]++;
        }
        return count;
    }

int main()
{
    vector<int> A = {4,3,1,2,4};
    cout<<beautifulSubarrays(A);
    return 0;
}