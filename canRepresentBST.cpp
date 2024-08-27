#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int canRepresentBST(int arr[], int N) {
        stack<int> s;
        int root = INT_MIN;

        for (int i = 0; i < N; i++) {
            if (arr[i] < root) {
                return 0;
            }

            while (!s.empty() && s.top() < arr[i]) {
                root = s.top();
                s.pop();
            }

            s.push(arr[i]);
        }

        return 1;
    }
};

int main() {
    Solution sol;

    int arr1[] = {2, 4, 3};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << sol.canRepresentBST(arr1, N1) << endl; // Output: 1

    return 0;
}
