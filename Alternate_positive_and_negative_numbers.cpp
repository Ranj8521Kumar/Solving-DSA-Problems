#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int>a;
        vector<int>b;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]>=0) {
                a.push_back(arr[i]);
            } else {
                b.push_back(arr[i]);
            }
        }
        arr.clear();
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0, k = 0;
        
        while(i < n && j < m) {
            if(k % 2 == 0) {
                arr.push_back(a[i]);
                i++;
            } else {
                arr.push_back(b[j]);
                j++;
            }
            k++;
        }
        while(i < n) {
            arr.push_back(a[i]);
            i++;
        }
        while(j < m) {
            arr.push_back(b[j]);
            j++;
        }
    }
};

int main() {
    vector<int> arr = {3, -2, -1, 4, -5, 6};
    Solution sol;
    sol.rearrange(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}