#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);

        if(n==0){
            return result;
        }

        result[0] = 0;

        for(int i = 1; i <= n; i++){
            result[i] = result[i / 2] + (i % 2);
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> result = sol.countBits(n);
    
    for(int i = 0; i <= n; i++){
        cout << "Number of 1's in binary representation of " << i << " is " << result[i] << endl;
    }

    return 0;
}
