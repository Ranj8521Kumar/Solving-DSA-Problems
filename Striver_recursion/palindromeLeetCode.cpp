#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string str;
    for (char c : s)
    {
        if (isalnum(c))
        {
            str.push_back(tolower(c));
        }
    }

    int N = str.length();
    for (int i = 0; i < N / 2; i++)
    {
        if (str[i] != str[N - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}