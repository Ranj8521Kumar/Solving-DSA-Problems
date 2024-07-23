#include<bits/stdc++.h>
using namespace std;

string largestNumber(const vector<int> &A) {
    vector<string> stringOfDigits;
    int n = A.size();

    for(int it : A){
        stringOfDigits.push_back(to_string(it));
    }
    
    sort(stringOfDigits.begin(), stringOfDigits.end(), [](const string &a, const string &b){
        return (a+b)>(b+a);
    });
    
    string result;
    for(const string &numStr: stringOfDigits){
        result += numStr;
    }
    
    if (result[0] == '0') {
        return "0";
    }
    
    return result;
}


int main()
{
    vector<int> A = {3, 30, 34, 5, 9};
    string result = largestNumber(A);
    cout<<result;
    return 0;
}