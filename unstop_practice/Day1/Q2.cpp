#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int index = n - k;
    cout << s[index] << endl;
    
    return 0;
}