#include<bits/stdc++.h>
using namespace std;
int print2largest(int arr[], int n) {
        int maxi = 0;
        int secondMaxi = -1;

        // Find the maximum and second maximum elements
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[maxi]) {
                secondMaxi = maxi;
                maxi = i;
            } else if(arr[i] < arr[maxi] && (secondMaxi == -1 || arr[i] > arr[secondMaxi])) {
                secondMaxi = i;
            }
        }

        // Check if distinct second maximum element exists
        if(maxi == secondMaxi || secondMaxi == -1) {
            return -1;
        }

        // Return the second largest distinct element
        return arr[secondMaxi];
    }

int main()
{
    int nums[] = {3, 4, 5, 1, 2};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout<<print2largest(nums, n);
    return 0;
}